#include <bits/stdc++.h>
#include "yuarel.h"

using namespace std;


class Merchant
{

    public:

    int id;
    float payout;

    Merchant()
    {
        id=0;
        payout=0;
    }

    Merchant(int id)
    {
        this->id = id;
        payout = 0;
    }
};

class Network
{
    public:
    string card_network;
    float percent;

    Network()
    {
        card_network="";
        percent=0;
    }

    Network(string card_network, float percent)
    {
        this->card_network = card_network;
        this->percent = percent;
    }
};

class Charge
{
    public:
    int id, amount, merchant_id;
    string network_name;

    Charge()
    {
        id=0;
        amount=0, merchant_id=0;
        network_name="";
    }

    Charge(int id, int amount, int merchant_id, string network_name)
    {
        this->id = id;
        this->amount = amount;
        this->merchant_id = merchant_id;
        this->network_name = network_name;
    }
};

unordered_map<string, Network> networks;
unordered_map<int, Charge> charges;
unordered_map<int, Merchant> merchants;


vector<string> split_string(string s)
{
    s += " ";
    vector<string> res;
    string wd = "";
    for (char ch : s)
    {
        if (ch == ' ')
        {
            res.push_back(wd);
            wd = "";
        }
        else
        {
            wd += ch;
        }
    }

    return res;
}

void charge(struct yuarel url)
{
    struct yuarel_param params[4];
    int n = yuarel_parse_query(url.query, '&', params, 4);
    int charge_id, merchant_id, amount;
    string network_name; //extract the parameters from actions string
    while (n--)
    {
        if (strcmp(params[n].key, "charge_id") == 0)
            charge_id = *params[n].val;
        else if (strcmp(params[n].key, "merchant_id") == 0)
            merchant_id = *params[n].val;
        else if (strcmp(params[n].key, "amount") == 0)
            amount = stoi(params[n].val);
        else if (strcmp(params[n].key, "network") == 0)
            network_name = params[n].val;
    }

    Charge newCharge(charge_id, amount, merchant_id, network_name); //create a new entry in charges hash table

    if(merchants.find(merchant_id)==merchants.end())
    {
    Merchant newMerchant(merchant_id);
    merchants[merchant_id]= newMerchant;

    }
    charges[charge_id] = newCharge;
}

void payout(struct yuarel url)
{
    struct yuarel_param params[1];
    yuarel_parse_query(url.query, '&', params, 1);

    int merchant_id = *params[0].val;                               //extract the merchant id from actions string
    int payout_balance = (int)ceil(merchants[merchant_id].payout); //get the corresponding payout_balance for the merchant using merchants hash

    merchants[merchant_id].payout = 0;          //set the payout to 0 after payout action
    cout << merchant_id << ", "<<payout_balance << endl; //print the paytout balance
}

void confirm(struct yuarel url)
{
    struct yuarel_param params[1];
    yuarel_parse_query(url.query, '&', params, 1);

    int charge_id = *params[0].val;

    if (charges.find(charge_id) != charges.end())
    {
        //extract the charge_id from actions string
        int amount = charges[charge_id].amount;                               //get the corresponding amount in the charge using charges hash
        float percent = networks[charges[charge_id].network_name].percent;    //get the corresponding percent of network_card using the merchant_id in charges and merchants hash
        float payout_balance = ((float)amount - 2 * percent * 0.01 * amount); //calculate the new payout balance

        merchants[charges[charge_id].merchant_id].payout += payout_balance; //update the payout of the merchant
        charges.erase(charge_id);
    }
}

void refund(struct yuarel url)
{
    struct yuarel_param params[1];

    yuarel_parse_query(url.query, '&', params, 1);

    int charge_id = *params[0].val; //extract the charge_id from actions string

    if (charges.find(charge_id) != charges.end())
    {
        int amount = charges[charge_id].amount;                            //get the corresponding amount in the charge using charges hash
        float percent = networks[charges[charge_id].network_name].percent; //get the corresponding percent of network_card using the merchant_id in charges and merchants hash
        float payout_balance = percent * 0.01 * amount;                    //calculate the new payout balance

        merchants[charges[charge_id].merchant_id].payout -= payout_balance; //update the payout after refund
        charges.erase(charge_id);
    }
}

void process_actions(vector<string> actions)
{

    int m, n;
    n = stoi(actions[0]);
    int i = 1;
    while (n--)
    {
        vector<string> card_details = split_string(actions[i]);

        string card_network = card_details[0];
        float percent = stof(card_details[1]);

        Network newNetwork(card_network, percent);

        networks[card_network] = newNetwork;
        i++;
    }

    m = stoi(actions[i++]);

    for (; i < actions.size(); i++)
    {
        struct yuarel url;
        string url_string=actions[i];
        char *temp = &(url_string[0]);
        yuarel_parse(&url, temp);

        char *params[1];
        yuarel_split_path(url.path, params, 1);

        string type = params[0]; //this will extract the type of action

        if (type.compare("charge") == 0)
        {
            charge(url);
        }

        else if (type.compare("payout") == 0)
        {
            payout(url);
        }
        else if (type.compare("confirm") == 0)
        {
            confirm(url);
        }
        else if (type.compare("refund"))
        {
            confirm(url);
        }
    }
}


int main()
{
    int n=9;
    vector<string> actions(n);
    for(int i=0;i<actions.size();i++)
    {
        cin>>actions[i];
    }

    process_actions(actions);

    return 0;
    
}

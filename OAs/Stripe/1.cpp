#include<bits/stdc++.h>
#include"yuarel.c"
using namespace std;

/* Data structure to store the details of a payment initiated by a customer */
struct payment
{
	string card;
	string merchantId;
	string chargeId;
	long long int amount;
};

/* Stripe Minimal SDK */
class Stripe
{
private:
	unordered_map<string, float> cardNetwork, paymentToMerchant;
	unordered_map<string, struct payment> pendingPayment;

public:
	void charge(struct yuarel url)	// Payment attempted by a customer towards a merchant
	{
		struct yuarel_param params[4];
		struct payment pay;

		int n = yuarel_parse_query(url.query, '&', params, 4);	// Parse the url query parameters
		while(n--)
		{
			if(strcmp(params[n].key, "charge_id")==0)
				pay.chargeId = params[n].val;
			else if(strcmp(params[n].key, "merchant_id")==0)
				pay.merchantId = params[n].val;
			else if(strcmp(params[n].key, "amount")==0)
				pay.amount = stoll(params[n].val);
			else if(strcmp(params[n].key, "network")==0)
				pay.card = params[n].val;
		}
		pendingPayment[pay.chargeId] = pay;	// Record the new payment as pending to be processed
	}

	void confirm(struct yuarel url)	 // Confirmation of a payment
	{
		struct yuarel_param params[1];
		yuarel_parse_query(url.query, '&', params, 1);	// Extract the charge_id from URL query parameter

		if(pendingPayment.find(params[0].val) != pendingPayment.end())
		{
			struct payment pay = pendingPayment[params[0].val];
			float rate = cardNetwork[pay.card];
			
			float amount = pay.amount - (pay.amount*rate)/100.0 - (pay.amount*2)/100.0;	// Deduct the card network and stripe processing fees
			paymentToMerchant[pay.merchantId] += amount;	// Add the amount to merchant's account
			pendingPayment.erase(params[0].val);	// Payment is confirmed, so remove it from the pending to be processed
		}
	}

	void refund(struct yuarel url)	// Cancellation of a payment
	{
		struct yuarel_param params[1];
		yuarel_parse_query(url.query, '&', params, 1);	// Extract the charge_id from URL query parameter

		if(pendingPayment.find(params[0].val) != pendingPayment.end())
		{
			struct payment pay = pendingPayment[params[0].val];
			float rate = cardNetwork[pay.card];
			float amount = (pay.amount*rate)/100.0;
			
			paymentToMerchant[pay.merchantId] -= amount;	// Deduct the card network processing fee
			pendingPayment.erase(params[0].val);	// Payment is cancelled, so remove it from the pending to be processed
		}
	}

	void payout(struct yuarel url)	// Balance settlement for a merchant
	{
		struct yuarel_param params[1];
		yuarel_parse_query(url.query, '&', params, 1);	// Extract the merchant_id from URL query parameter

		long long int payoutBalance = ceil(paymentToMerchant[params[0].val]);
		paymentToMerchant[params[0].val] = 0;	// Reset the merchant's payout balance

		cout<<params[0].val<<", "<<payoutBalance<<"\n";
	}

	void buildCardNetwork(int n, vector<string> input_lines)	// Build card network of credit card used for payment
	{
		for(int i=1; i<=n; i++)
		{
			vector<string> cardDetails = splitString(input_lines[i]);
			cardNetwork[cardDetails[0]] = stof(cardDetails[1]);
		}
	}

private:
	vector<string> splitString(string s)	// Split the sentence into words around spaces and return the resultant as array
	{
		s += " ";
		vector<string> result;
		string word = "";
		for (char ch : s)
		{
			if (ch == ' ')
			{
				result.push_back(word);
				word = "";
			}
			else
			{
				word += ch;
			}
		}
		return result;
	}
};

void process_actions(vector<string> input_lines)
{
	Stripe obj;	// Create a new object of Stripe SDK
	int n = stoi(input_lines[0]);	// Get the number of cards
	obj.buildCardNetwork(n, input_lines);	// Build the card network

	for(int i=n+2; i<input_lines.size(); i++)	// Process all the actions
	{
		string action = input_lines[i];
		struct yuarel url;

		char *temp = &(action[0]);
		
		yuarel_parse(&url, temp);
		char *parts[1];
		yuarel_split_path(url.path, parts, 1);	// Extract the type of action from string

		if(strcmp(parts[0], "charge")==0)
			obj.charge(url);
		else if(strcmp(parts[0], "confirm")==0)
			obj.confirm(url);
		else if(strcmp(parts[0], "refund")==0)
			obj.refund(url);
		else if(strcmp(parts[0], "payout")==0)
			obj.payout(url);
	}
}

int main()
{
	/*
		"2",
		"visa 2",
		"mastercard 3",
		"8",
		"/charge?merchant_id=m001&charge_id=c001&amount=1000&network=visa",
		"/charge?network=mastercard&amount=1000&merchant_id=m001&charge_id=c002",
		"/confirm?charge_id=c001",
		"/confirm?charge_id=c002",
		"/payout?merchant_id=m001",
		"/charge?merchant_id=m001&charge_id=c003&amount=1000&network=visa",
		"/confirm?charge_id=c003",
		"/payout?merchant_id=m001"
	*/

	vector<string> input_lines
	{
		"2",
		"visa 2.0",
		"mastercard 3.0",
		"5",
		"/charge?merchant_id=m001&charge_id=c001&amount=100&network=visa",
		"/charge?network=mastercard&amount=56&merchant_id=m001&charge_id=c002",
		"/refund?charge_id=c001",
		"/confirm?charge_id=c002",
		"/payout?merchant_id=m001"
	};

	process_actions(input_lines);

    return 0;
}
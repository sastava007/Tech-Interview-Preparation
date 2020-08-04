/* 
    Design a logger system that receive stream of messages along with its timestamps, each message should be printed if and only if it isnot printed in the last 10 seconds.

    So a bruteforce approach would be to maintain a hashtable with message as key and time as value, and only print those messages which doesn't exists yet or not been seen in last
    10 seconds. But this approach would not work, if we gat a large stream of logs in that case we have to remove the obselete logs that are older than 10 sec from the system.

    TC & Space: O(N)
*/

class Logger
{
    queue<pair<string,int>> q;
    unordered_set<string> message;

public:
    Logger()
    {

    }
    bool shouldPrintMessage(string msg, int timestamp)
    {
        while(!q.empty() && q.top().second <= timestamp-10) //discard the obsolete message which are older than 10 sec
        {
            auto log = q.front();
            q.pop();
            message.erase(log.first);
        }

        if(message.find(msg)==msg.end())
        {
            q.push({msg, timestamp});
            message.insert(msg);
            return true;
        }
        return false;
    }
};


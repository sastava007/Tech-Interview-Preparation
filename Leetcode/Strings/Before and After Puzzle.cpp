/* 
    Given a list of phrases, with few of them having cases where starting word of one phrase is equal to ending word of other.
    We've to combine all such phrases into one.

    Input: [writing code, code rocks]
    Output:[writing code rocks]

    TC: O(N)

    So idea is to first extract the starting word and map it's index in a hash table, and later iterate over the array and find whether the ending word matches with any word in hashtable
    or not, if matches then simply append those.

*/

private static List<String> generatePhrases(List<String> inputs) 
{
        List<String> result = new ArrayList<>();
        Map<String, List<Integer>> firstWordMap = new HashMap<>();      // Using a unordered_map<string, vector<int>> becz there could be many different phrases with same starting word
        for(int i=0; i<inputs.size(); ++i)                             // And it may be possible that there are more than 1 pair of string which shares common starting/ending word.
        {                                   
            String str = inputs.get(i);
            String firstWord = str.substring(0, str.indexOf(' '));
            firstWordMap.putIfAbsent(firstWord, new ArrayList<>());
            firstWordMap.get(firstWord).add(i);
        }
        
        for(int i=0; i<inputs.size(); i++) 
        {
            String str = inputs.get(i);
            String lastWord = str.substring(str.lastIndexOf(' ') + 1);      // Can use while() from ending in C++
            if(firstWordMap.containsKey(lastWord)) 
            {
                List<Integer> indexes = firstWordMap.get(lastWord);
                for(Integer index : indexes) 
                {
                    if(i != index) 
                    {
                        String temp = inputs.get(index);
                        result.add(str + temp.substring(temp.indexOf(' ')));
                    }
                }
            }
        }
        return result;     
    }


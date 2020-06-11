/* We can Use Trie (reverse dictionary words) with pruning stream data */


class Trie {
	unordered_map<char, Trie *> char_map;
	bool word_ends;
public:
	Trie() {
		word_ends = false;
	}

	void insert(string word) {
		if(word.length() == 0)
			return;

		Trie *temp = this;
		for(auto ch : word) {
			if(temp->char_map.find(ch) != temp->char_map.end()) {
				temp = temp->char_map[ch];
			} else {
				temp->char_map[ch] = new Trie();
				temp = temp->char_map[ch];
			}
		}
		temp->word_ends = true;
	}

	bool search(string word) {
		if(word.length() == 0)
			return false;

		Trie *temp = this;
		for(auto ch : word) {
			if(temp->char_map.find(ch) == temp->char_map.end())
				return false;
			temp = temp->char_map[ch];
			if(temp->word_ends)
				return true;
		}
		return temp->word_ends;
	}
};

class StreamChecker {
	Trie my_trie;
	string str = "";
	int w_len = 0;
public:
	StreamChecker(vector<string>& words) {
		for(auto w : words) {
			reverse(w.begin(), w.end());
			w_len = max(w_len, (int)w.length());
			my_trie.insert(w);
		}
	}

	bool query(char letter) {
		str = letter + str;

		if(str.length() > w_len)
			str.pop_back();

		return my_trie.search(str);
	}
};
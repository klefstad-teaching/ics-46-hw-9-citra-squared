#include "ladder.h"

void error(string word1, string word2, string msg) {
    std::cout << "ERROR: " << word1 << " & " << word2 << ": " << msg << std::endl;
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    if (begin_word == end_word) {
        error(begin_word, end_word, "words shouldn't be the same");
        return {};
    }
    
    queue<vector<string>> ladder_queue; 
    ladder_queue.push({begin_word}); 

    set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> current_ladder = ladder_queue.front(); 
        ladder_queue.pop(); 
       
        string last_word = current_ladder[current_ladder.size() - 1]; 

        for (string word : word_list) {
             
            if (is_adjacent(last_word, word)) {
                if (visited.count(word) == 0) {
                    visited.insert(word); 

                    vector<string> new_ladder = current_ladder; 
                    new_ladder.push_back(word); 

                    if (word == end_word) {
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder); 
                }
            }
        }
    }
    return {};
}
    

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int n1 = str1.length();
    int n2 = str2.length();

    int ed = 0;

    if (n1 == n2) {
        for (int i = 0; i < n1; i++) {
            if (str1[i] != str2[i]) {
                ed++;
                if (ed > d) {
                    return false;
                }
            }
        }
    } else {
        if (abs(n1 - n2) > 1) {
            return false;
        }
        
        int i = 0; int j = 0;

        while (i < n1 && j < n2) {
            if (str1[i] != str2[j]) {
                if (n1 > n2) {
                    i++;
                } else {
                    j++;
                }
                ed++;
                if (ed > d) {
                    return false;
                }
            } else {
                
                i++;
                j++; 
            }
        }

        ed += (n1 - i);
        ed += (n2 - j); 
        if (ed > d) {
            return false;
        }
        
        
    }
    return true;
}
                


void load_words(set<string> & word_list, const string& file_name) {
    ifstream in(file_name);

    for (string word; in >> word;) {
        word_list.insert(word); 
    }
    in.close();
}

void print_word_ladder(const vector<string>& ladder) {
    if (ladder.size() == 0) {
        std::cout << "No word ladder found.";
    }
    for (auto word : ladder) {
        std::cout << word << " ";
    }
    std::cout << "\n"; 
}

void my_assert(int a, int b) {
    std::cout << a << " " << b << std::endl; 
    if (a == b) {
        std::cout << "passed\n";
    } else {
        std::cout << "failed\n";
    }
}

void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "src/words.txt");

    vector<string> new_word_ladder = generate_word_ladder("cat", "dog", word_list);
    print_word_ladder(new_word_ladder); 
    my_assert(new_word_ladder.size(), 4);
    new_word_ladder = generate_word_ladder("marty", "curls", word_list); 
    print_word_ladder(new_word_ladder); 
    my_assert(new_word_ladder.size(), 6);
    new_word_ladder = generate_word_ladder("sleep", "awake", word_list);
    print_word_ladder(new_word_ladder); 
    my_assert(new_word_ladder.size(), 8);
}
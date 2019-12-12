#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

class MorseMachine {
  public:
    MorseMachine(string morse_file_path) {
      this->encode_map = map<string, string>();
      
      // initialize the map
      ifstream morsefile("morse.txt");
      string letter, morsestr;
      while (morsefile >> letter >> morsestr) {
        #ifndef NDEBUG
        cout << "Letter: " << letter << " " << morsestr << endl;
        #endif
        encode_map.insert(pair<string,string>(letter, morsestr));
        decode_map.insert(pair<string,string>(morsestr, letter));
      }

      morsefile.close();
    }
    
    string encode(string plaintext) {
      string encoded = "";
      map<string,string>::iterator it;
      for (char& c : plaintext) {
        it = this->morse_map.find(string(1, c));
        if (it != this->morse_map.end()) {
          #ifndef NDEBUG
          cout << "Encoding: " << c << " as " << it->second << endl;
          #endif
          encoded = encoded + it->second + " ";
        } else {
          #ifndef NDEBUG
          cout << "Not encoding: '" << c << "'" << endl;
          #endif
          encoded = encoded + string(1, c);
        }        
      }
      return encoded;
    }    

    // Big O is O(n), n being the number of characters we need to decode
    // Map size stays static so searching it is O(1)
    string decode(string encoded) {
      string decoded = "";
      // create a string stream for easily finding space delimited words
      stringstream encoded_stream(encoded);
      // iterate over space delimited words in encoded string
      string encoded_char;
      while (encoded_stream >> encoded_char
    }

  private:
    // uses two maps, one for each operation
    map<string, string> encode_map;
    map<string, string> decode_map;
};

int main() {
  MorseMachine mm = MorseMachine("morse.txt");
  string test_plaintext = "asdf asdf asdf";
  cout << mm.encode(test_plaintext) << endl;
}
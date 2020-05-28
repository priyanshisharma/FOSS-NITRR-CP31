//
//
class Solution {
public:
    bool findit(vector<string> &banned, string ban)
    {
        for (int i=0;i<banned.size();i++)
        {
            if(banned[i]==ban)
                return true;
        }
        return false;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        unordered_map<string,int> parafreq;
        int max = 0,max_loc =0;
        string word;
        vector<string> words;
        int i=0;
        while(i<paragraph.length())
        {
           // cout<<'a';
            
            while((paragraph[i]>='a'&&paragraph[i]<='z')||(paragraph[i]>='A'&&paragraph[i]<='Z'))
            {
             //   cout<<'b';
                
                if(paragraph[i]>='A'&&paragraph[i]<='Z')
                {
                    paragraph[i] = paragraph[i] - 'A' + 'a';
                }
                word.push_back(paragraph[i++]);
                
            }
            i++;
          //  cout<<'c';
           // cout<<'#'<<word<<'#'<<endl;
            if(word.size()>0&&!findit(banned, word))
            {
              //  cout<<'d'<<word<<' '<<max<<' '<<parafreq[word];
                parafreq[word]++;
                if(parafreq[word]>max)
                {
                  //  cout<<word;
                    max = parafreq[word];
                    words.push_back(word);
                }    
            }
          //  cout<<'e';
          //  cout<<word<<'#'<<' ';
          //  cout<<max;
            word.clear();
        }
        
        return words[words.size()-1];

    }
};

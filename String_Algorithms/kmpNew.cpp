vector<int> getLPS(string& patteren){
        int patterenLength = patteren.size();
        vector<int> lps(patterenLength, 0);
        
        int right = 1;
        int left = 0;
        
        while(right < patterenLength){
            if(patteren[right] == patteren[left]){
                lps[right] = left + 1;
                left++;
                right++;
            }else{
                if(left == 0 ){
                    lps[right] = 0;
                    right++;
                } else{
                    left = lps[left - 1];
                }
            }
        }
        
        return lps;
    }
    
    int strStr(string haystack, string needle) {
        vector<int> lps = getLPS(needle);
        
        int patterenIndex = 0;
        int textIndex = 0;
        
        int textLength = haystack.size();
        int patterenLength = needle.size();
        
        while(textIndex < textLength) {
            if(haystack[textIndex] == needle[patterenIndex]){
                textIndex++;
                patterenIndex++;
            }
            
            if(patterenIndex == patterenLength){
                return textIndex - patterenIndex;
            }
            
            if(textIndex < textLength && haystack[textIndex] != needle[patterenIndex]){
                if(patterenIndex == 0 ){
                    textIndex++;
                } else{
                    patterenIndex = lps[patterenIndex - 1];
                }
            }
        }
        return -1;
    }

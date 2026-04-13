
class Solution {
    
public:
    int minOperations(vector<string>& logs) {

        int count = 0;
        for(int i=0; i< logs.size(); i++){
            string log = logs[i];

            if(log == "../"){
                if(count > 0){
                    count--;
                }
                
            }
            else if(log == "./"){
                    continue;
            }

            else{
                count++;
            }
        }

        return count;
        
    }
};
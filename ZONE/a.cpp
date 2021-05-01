#include<iostream>
#include<string>

int main(){
    std::string s;
    std::cin>>s;

    std::string zone="ZONe";
    int ans=0;
    int cnt=0;
    for(int i=0;i<s.size();i++){

        if(s[i]==zone[cnt]){
            cnt++;
        }
        else if(s[i]==zone[0]){
            cnt=1;
        }
        else{
            cnt=0;
        }

        if(cnt==zone.size()){
            ans++;
            cnt=0;
        }
    }
    std::cout<<ans<<std::endl;
    return 0;
}
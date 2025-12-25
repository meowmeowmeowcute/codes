# include<bits/stdc++.h>
using namespace std;

int main(){
    int w1, w2, h1, h2, n, inp, a1, a2, maximum = 0;
    cin >> n >> w1 >> w2>> h1 >> h2;
    a1 = w1*w1;
    a2 = w2*w2;
    int total = 0;
    int cup_one = a1*h1;
    int cup_all = cup_one+a2*h2;
    for (int i = 0; i<n; i++){
        cin >> inp;
        total+=inp;
        if (total<=cup_all){
            //check the height2
            if (total<=cup_one){
                maximum = max(maximum, inp/a1);
            }
            else if (total-inp>cup_one){
                maximum = max(maximum, inp/a2);
            }
            else{
                maximum = max(maximum, (cup_one-(total-inp))/a1+(total-cup_one)/a2);
            }
        }
        else{
            if (total-inp<cup_all){
                if (total-inp<=cup_one){
                    maximum = max(maximum, (cup_one-(total-inp))/a1+(cup_all-cup_one)/a2);
                }
                else{
                    maximum = max(maximum, (cup_all-(total-inp))/a2);
                }
            }
        }
    }
    cout << maximum << endl;
    return 0;
}
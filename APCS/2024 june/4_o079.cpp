# include <bits/stdc++.h>
# define ll long long
# define ARR (int)3e5 
# define plli pair<ll, int>
using namespace std;

int n, k, graph_inp[ARR], inp_typ[ARR], inp;
ll maximum = 0;
vector<plli> plli_pre_zero, plli_suf_zero;
vector<plli> plli_pre_pos[ARR], plli_suf_pos[ARR], plli_pre_neg[ARR], plli_suf_neg[ARR];

void bin_sch(vector<plli>& vec, ll k, ll cr_ans, int idx, int left, int right){
    int ans = -1;
    if (!vec.empty())
        while(left <= right){
            int mid = (left+right)/2;
            if (vec[mid].first <= k-cr_ans && vec[mid].second>=idx){
                ans = vec[mid].first;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }

    if (ans!=-1){
        maximum = max(maximum, ans+cr_ans);
    }
}

// all idx must be the last
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    //input init
    for (int i = 0; i<n; i++){
        cin >> inp;
        graph_inp[i] = inp;
        // even typ 1
        if (inp%2 == 0){
            inp_typ[i] = 1;
        }else{
            inp_typ[i] = -1;
        }
    }
    //pre
    int pre_typ_tot = 0;
    ll pre_tot = 0;
    for (int i = 0; i<n; i++){
        pre_typ_tot+=inp_typ[i];
        pre_tot+=graph_inp[i];
        if (pre_typ_tot == 0){
            plli_pre_zero.push_back({pre_tot, i});
        }else if (pre_typ_tot > 0){
            plli_pre_pos[pre_typ_tot].push_back({pre_tot, i});
        }else{
            plli_pre_neg[-1*pre_typ_tot].push_back({pre_tot, i});
        }
    }
    int suf_typ_tot = 0;
    ll suf_tot = 0;
    for (int i = n-1; i>=0; i--){
        suf_typ_tot+=inp_typ[i];
        suf_tot+=graph_inp[i];
        if (suf_typ_tot == 0){
            plli_suf_zero.push_back({suf_tot, i});
        }else if (suf_typ_tot > 0){
            plli_suf_pos[suf_typ_tot].push_back({suf_tot, i});
        }else{
            plli_suf_neg[-1*suf_typ_tot].push_back({suf_tot, i});
        }
    }

    bin_sch(plli_pre_zero, k, 0, 0, 0, plli_pre_zero.size()-1);
    bin_sch(plli_suf_zero, k, 0, 0, 0, plli_suf_zero.size()-1);

    for(int i = 0; i<ARR; i++){
        vector<plli> vec_pre = plli_pre_pos[i];
        for(plli pai_lli_pre : vec_pre){
            bin_sch(plli_suf_neg[i], k, pai_lli_pre.first, pai_lli_pre.second+1, 0, plli_suf_neg[i].size()-1);
        }
    }

    for(int i = 0; i<ARR; i++){
        vector<plli> vec_pre = plli_pre_neg[i];
        for(plli pai_lli_pre : vec_pre){
            bin_sch(plli_suf_pos[i], k, pai_lli_pre.first, pai_lli_pre.second+1, 0, plli_suf_pos[i].size()-1);
        }
    }
    cout << maximum;
}



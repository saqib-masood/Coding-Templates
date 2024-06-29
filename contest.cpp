#define ll long long
class segsum{
    public:
    ll seg[400005]={0};
    void updateup(ll ss,ll se,ll v,ll ind,ll val){
        if(ss>se or ind<ss or ind>se)
            return;
        if(ss==se) {
            seg[v]=val;
            return;
        }
        ll mid=ss+(se-ss)/2;
        if(ind>mid)
            updateup(mid+1,se,2*v+1,ind,val);
        else
            updateup(ss,mid,2*v,ind,val);
        seg[v]=seg[2*v+1]+seg[2*v];
 
    }
    void update(ll ind,ll val)
    {
        updateup(1,1e5,1,ind,val);
    }
    int query(int qs,int qe)
    {
        return  queryup(1,1e5,qs,qe,1);
    }
    int queryup(int ss,int se,int qs,int qe,int v)
    {
        if(qs>se or qe<ss)
            return 0;
        if(qs<=ss and se<=qe)
            return seg[v];
        ll mid=ss+(se-ss)/2;
        return queryup(ss,mid,qs,qe,2*v)+queryup(mid+1,se,qs,qe,2*v+1);
    }
};
class segmax{
    public:
    ll seg[400005]={0};
    ll updateup(ll s,ll e,ll ind,ll node,ll val)
    {
        if(s>e) return -1e9;
        if(s==e)
        {
            seg[node]=val;
            return seg[node];
        }
        ll mid=(s+e)/2;
        if(ind>=s and ind<=mid) updateup(s,mid,ind,2*node,val);
        else updateup(mid+1,e,ind,2*node+1,val);
        seg[node]=max(seg[2*node],seg[2*node+1]);
        return seg[node];
    }
    void update(ll ind,ll val)
    {
        updateup(1,1e5,ind,1,val);
    }
    int queryup(int ss,int se,int qs,int qe,int v)
    {
            if(qs>se or qe<ss)
                return -1e9;
            if(qs<=ss and se<=qe)
                return seg[v];
            ll mid=ss+(se-ss)/2;
            return max(queryup(ss,mid,qs,qe,2*v),queryup(mid+1,se,qs,qe,2*v+1));
    }
    int query(int qs,int qe){
        return  queryup(1,1e5,qs,qe,1);
    }
};
 
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int> s;
        vector<bool> ans;
        segmax sm;
        segsum ss;
        s.insert(1e5);
        for(auto q: queries){
            int typ=q[0];
            if(typ==1){
                int sum=ss.query(1,q[1]);
                int next=*s.lower_bound(q[1]+1);
                ss.update(q[1],q[1]-sum);
                ss.update(next,next-q[1]);
                sm.update(q[1],q[1]-sum);
                sm.update(next,next-q[1]);
                s.insert(q[1]);
            }
            else {
                int x=q[1],maxi=sm.query(1,x),sum=ss.query(1,x);
                maxi=max(maxi,x-sum);
                ans.push_back(maxi>=q[2]);
            }
        }
        return ans;
    }
};
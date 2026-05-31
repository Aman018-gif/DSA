// Block Placement Queries
// There exists an infinite number line, with its origin at 0 and extending towards the positive x-axis.

// You are given a 2D array queries, which contains two types of queries:

// For a query of type 1, queries[i] = [1, x]. Build an obstacle at distance x from the origin. It is guaranteed that there is no obstacle at distance x when the query is asked.
// For a query of type 2, queries[i] = [2, x, sz]. Check if it is possible to place a block of size sz anywhere in the range [0, x] on the line, such that the block entirely lies in the range [0, x]. A block cannot be placed if it intersects with any obstacle, but it may touch it. Note that you do not actually place the block. Queries are separate.
// Return a boolean array results, where results[i] is true if you can place the block specified in the ith query of type 2, and false otherwise.
// Approach 1: Segment Tree
// Intuition
// The question is essentially asking whether there exists a blank interval of length at least sz that is completely contained within the range [0,x].

// To help maintain these blank intervals, we define p[i] as the position of the nearest obstacle to the left of i. Then, d[i]=i−p[i] represents the length of the maximum blank interval ending at position i.

// For each query with parameters x and sz, the problem becomes determining whether there exists an index i≤x such that d[i]≥sz. In other words, we need to check whether the maximum value of d[i] in the interval [0,x] is at least sz.

// We do not need to maintain every individual point. Instead, we only need to maintain the lengths of the intervals. The next question is where to store these interval lengths so that queries can be processed efficiently.

// Observe that each query consists of several complete intervals and at most one incomplete interval truncated by x. We can store the length of each interval at its right endpoint. Specifically, we store d[r] at the right endpoint r, where for every complete interval, d[r] equals the distance to the nearest obstacle on the left.

// The remaining problem is how to maintain the d array dynamically. We can use a segment tree to support point updates and range maximum queries.

// Let pre and nxt denote the positions of the nearest obstacles to the left and right of x, respectively. When inserting an obstacle at position x, we need to update both d[x] and d[nxt].

// During a query, the interval [0,pre] consists entirely of complete intervals, so we can directly query it using the segment tree. The remaining incomplete interval [pre,x] is handled separately by comparing its length with sz.

// We also need to efficiently determine the nearest obstacles on both sides of x, which requires maintaining an ordered structure during insertions. A balanced binary search tree can be used for this purpose.

class Solution {
public:
    vector<int> seg;
    void update(int idx,int val,int p,int l, int r){
        if(l==r) {
            seg[p]=val;
            return;
        }
        int mid = (l+r)>>1;
        if(idx<=mid){
            update(idx,val,p<<1,l,mid);
        }
        else{
            update(idx,val,p<<1|1,mid+1,r);
        }
        seg[p] = max(seg[p<<1],seg[p<<1|1]);
    }

    int query(int L,int R,int p,int l,int r){
        if(L<=l && r<=R){
            return seg[p];
        }
        int mid = (l+r)>>1;
        int res =0;
        if(L<=mid){
            res = max(res, query(L,R,p<<1,l,mid));
        }
        if(R>mid) {
            res = max(res,query(L,R,p<<1|1,mid+1,r));
        }
        return res;
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 50000;
        seg.resize(mx<<2);
        set<int> st ={0,mx};
        update(mx,mx,1,0,mx);
        vector<bool>ans;
        for(auto &q:queries){
            if((q[0]==1)){
                int x = q[1];
                auto it = st.upper_bound(x);
                int r = *it;
                int l = *prev(it);
                update(x,x-l,1,0,mx);
                update(r,r-x,1,0,mx);
                st.insert(x);
            }
            else{
                int x =q[1];
                int sz = q[2];
                auto it = st.upper_bound(x);
                --it;
                auto prev = *it;
                int max_space = query(0,prev,1,0,mx);
                max_space = max(max_space,x-prev);
                ans.push_back(max_space>= sz);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n=seats.size();
        sort(students.begin(), students.end());
        sort(seats.begin(), seats.end());

        int ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(students[i]-seats[i]);
        }
        return ans;
    }
};
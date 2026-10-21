class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int [] answer = new int[n];
        for(int[] booking : bookings){
            int left =booking[0];
            int right =booking[1];
            int seats =booking[2];
            answer[left-1]+=seats;
            if(right!=n){
                answer[right]-=seats;
            }
        }
        for(int i=1;i<n;i++){
            answer[i]=answer[i]+answer[i-1];
        }
        return answer;
    }
}
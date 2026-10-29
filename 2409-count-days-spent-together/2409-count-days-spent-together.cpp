class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        // sum(days of month ) + day
        int alicearrivedate = stoi(arriveAlice.substr(3, 2));;
        int aliceleavedate = stoi(leaveAlice.substr(3, 2));
        int bobarrivedate = stoi(arriveBob.substr(3, 2));
        int bobleavedate = stoi(leaveBob.substr(3, 2));
        int alicearrivemonth = stoi(arriveAlice.substr(0, 2));
        int aliceleavemonth = stoi(leaveAlice.substr(0, 2)) ;
        int bobarrivemonth = stoi(arriveBob.substr(0, 2)) ;
        int bobleavemonth = stoi(leaveBob.substr(0, 2)) ;
        // int month = stoi(date.substr(0, 2)); // "08" -> 8
        // int day = stoi(date.substr(3, 2));   // "15" -> 15
        for(int i = 0 ; i < alicearrivemonth-1 ; i++){
            alicearrivedate = alicearrivedate + days[i];
        }
        for(int i = 0 ; i < aliceleavemonth-1 ; i++){
            aliceleavedate = aliceleavedate + days[i];
        }for(int i = 0 ; i < bobarrivemonth-1 ; i++){
            bobarrivedate = bobarrivedate + days[i];
        }for(int i = 0 ; i < bobleavemonth-1 ; i++){
            bobleavedate = bobleavedate + days[i];
        }
        int start = max(alicearrivedate , bobarrivedate);
        int end = min(aliceleavedate , bobleavedate);
        if(start>end) return 0 ;
        return end - start + 1;
    }
};
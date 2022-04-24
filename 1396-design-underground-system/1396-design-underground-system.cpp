class UndergroundSystem 
{
public:
    unordered_map<int,pair<string,int>>mpin;
     unordered_map<string,pair<int,int>>mpout;
    UndergroundSystem() 
    {   
    }
    void checkIn(int id, string stationName, int t) 
    {   
        mpin[id]={stationName,t};
    }
    void checkOut(int id, string stationName, int t) 
    {   
        auto it=mpin[id];
        string new_station=it.first+"->"+stationName;
        mpout[new_station].first+=t-it.second;
        mpout[new_station].second++;
    }
    double getAverageTime(string startStation, string endStation) 
    {   
        string new_string=startStation+"->"+endStation;
        return (double)((mpout[new_string].first+0.0)/mpout[new_string].second);
    }
};
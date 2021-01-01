/* 
    Given a list of trips and a car with sitting capacity, and starting, end location and no. of ppl to pick from that location. Find whether it is possible to pick everyone
    in that trip or not.  trip[i] = [num_passengers, start_location, end_location]

    Idea: This ques is similar to Meeting Rooms 2/ Minimum platform problem where we were supposed to find minimum no. of rooms for all the meetings and there we've used
    a multimap to map the arrival and departure point of trains and add +1 for each platform and -1 for each departure and while doing so maintain the maximum platforms
    required.
*/

// TC: O(NlogN) and Space: O(M) where N = no. of trips, and M = no. of stops
bool carPooling(vector<vector<int>> &trips, int capacity)
{
    map<int, int> stops;
    for (auto trip : trips)
    {
        stops[trip[1]] += trip[0]; // add no. of ppl loaded into car at this stop
        stops[trip[2]] -= trip[0]; // subtract the no. of ppl unloaded from car at this stop
    }

    for (auto it : stops)
    {
        capacity -= it.second; // Now adjust the remaining/ unbalanced ppl left at that particular stop in the capacity
        if (capacity < 0)      // and if this capacity ever runs <0 which means that we get short of seats in car to accomodate everyone.
            return false;
    }

    return true;
}

/* 
    Since we only have 1,001 stops, we can just figure out how many people get it and out in each location.
    Process all trips, adding passenger count to the start location, and removing it from the end location. After processing all trips, a positive value for the specific location tells
    that we are getting more passengers; negative - more empty seats.

    Finally, scan all stops and check if we ever exceed our vehicle capacity.

    TC: O(N) and Space: O(M) where N = no. of trips, and M = no. of stops
*/

bool carPooling(vector<vector<int>>& trips, int capacity)
{
  int stops[1001] = {};
  for (auto t : trips) stops[t[1]] += t[0], stops[t[2]] -= t[0];
  for (auto i = 0; capacity >= 0 && i < 1001; ++i) capacity -= stops[i];
  return capacity >= 0;
}
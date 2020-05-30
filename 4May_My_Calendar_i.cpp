//Problem 6
// https://leetcode.com/problems/my-calendar-i/

//Initial solution without lower_bound function has been commented below

class MyCalendar {
    set<pair<int,int>> booking;
public:
    MyCalendar() {
        booking.clear();
    }
    
    bool book(int start, int end) {
        
        pair<int,int> book = make_pair(start,end);
        set<pair<int,int>> ::iterator itr = booking.lower_bound(book);
        if(itr!=booking.end()&&itr->first<end)
            return false;
        if(itr!=booking.begin()&& (--itr)->second>start)
            return false;
        booking.insert(book);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
 
 /*
 class MyCalendar {
    set<pair<int,int>> booking;
public:
    MyCalendar() {
        booking.clear();
    }
    
    bool book(int start, int end) {
        
        pair<int,int> book = make_pair(start,end);
        for(pair<int,int> b : booking )
        {

            if(book.second>b.first&&book.first<b.second)
                return false;
            
        }
        booking.insert(book);
        return true;
    }
};
*/
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
 
 
 

class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        const pair<int, int> timeSlot(start, end);
        const auto nextTimeSlot = bookedTimeSlots.lower_bound(timeSlot);

        if(nextTimeSlot != bookedTimeSlots.end() 
            && nextTimeSlot->first < end) {
            return false;
        }

        if(nextTimeSlot != bookedTimeSlots.begin()) {
            const auto prevTimeSlot = prev(nextTimeSlot);

            if(prevTimeSlot->second > start) {
                return false;
            }
        }

        bookedTimeSlots.insert(timeSlot);
        return true;
    }

private:
    set<pair<int, int>> bookedTimeSlots;
};

// Sorted Vector
// Binary Search

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */


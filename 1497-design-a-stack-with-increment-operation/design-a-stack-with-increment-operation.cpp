struct ll{
    int num;
    ll* next;
    ll(){
        num = -1;
        next = nullptr;
    }
};

class CustomStack {
int totsize;
int op = 0;
ll *results = new ll();
ll* beg = results;
public:
    CustomStack(int maxSize) {
        totsize = maxSize;
    }
    
    void push(int x) {
        if(op<totsize){
            ll* novo = new ll();
            novo->num = x;
            novo->next = results;
            results = novo;
            op++;
        }
    }
    
    int pop() {
        if(op>0){
        int res = results->num;
        results = results->next;
        op--;
        return res;
        }
        else{
            return results->num;
        }
    }
    
    void increment(int k, int val) {
        int i = 0;
        ll* incr = results;
        int offset = op - k;
        while(i<offset){
            incr = incr->next;
            i++;
        }
        while(incr->next != nullptr){
            incr->num = incr->num + val;
            incr = incr->next;
        }
    }
};
#include <iostream> 

enum status {
    STARVE,
    POISON,
    POKE
};


class creature {
    private:
        int health = 100;
        int hunger = 100;

    public:
        int status_values[] {0,0,0};

        void tick() {
        
        };
};

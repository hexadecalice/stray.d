#define MAX_HEALTH 100
#define MAX_HUNGER 100

enum status {
    STARVE,
    POISON,
    POKE,
    MAX_STATUS // Not a real status. Helps us count how many we've implemented.
};

class creature {
    private:
        int health = MAX_HEALTH;
        int hunger = MAX_HUNGER;
        int status_values[MAX_STATUS]{0};
};

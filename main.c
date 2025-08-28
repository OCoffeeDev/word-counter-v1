#include "word_counter.h"

int main()
{

    Counter c;

    // Introduction to system
    introduction(&c);

    // Write the original phrase
    original_phrase(&c);

    // Write the word you want to count
    if (c.answer[0] == 'y')
    {
        selected_word(&c);
        selected_word_counter(&c);
    }

    // Total words of the phrase
    total_words(&c);

    // Print
    print(&c);

    return 0;
}
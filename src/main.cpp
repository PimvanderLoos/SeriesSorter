#include "main.ih"

int main()
{
    while(true)
    {
        {
            FileReader fr;
            fr.run();
        }
        // Run every 5 minutes
        sleep(300);
    }
}
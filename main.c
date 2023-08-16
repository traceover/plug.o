// This tells gcc the calling convention of the function, since
// its definition is in another file that will be loaded dynamically
// NOTE: The extern keyword is not required for functions, but I like it to be explicit
extern void plug(int x);

int main(void)
{
    plug(127); // If this works, we should see "Hello from plugin: 127"
    return 0;
}
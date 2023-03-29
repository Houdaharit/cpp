int main(int argc, char **argv)
{
    (void)argv;
    if (argc > 1)
    {
        std::map<std::string, float> data;
        data = database_data();
        display(argv[1], data);
    }
    return 0;
}

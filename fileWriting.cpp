void writeToFile(struct Text* sorted, const char* const fileName)
{
    FILE* fp = fopen(fileName, "wb");
    if(fp == NULL)
    {
        //TODO errorcodes
    }

    fprintf(fp, "Alphabetically sorted:\n\n\n")
    //fwrite(Text.);

}
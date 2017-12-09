static int DEFAULT_ELEMENT = -1;
template <const ScoreSheet::Color C>
QwintoRow<C>::QwintoRow()
{
    if (C == ScoreSheet::Color::RED)///CHANGED FOR TESTING DANGER
    {
        for (int i = 0; i < 10; ++i)
        {
            if (i == 3)
            {
                row[i] == -2;
            } //-2 stands for the XX on the board
            else
            {
                row[i] = -1;
            }
        }
    }
    else if (C == ScoreSheet::Color::YELLOW)//CHANGED FOR TESTING
    {
        for (int i = 0; i < 10; ++i)
        {
            if (i == 5)
            {
                row[i] == -2;
            }
            else
            {
                row[i] = -1;
            }
        }
      //  row[9]=10;
    }
    else if (C == ScoreSheet::Color::BLUE)
    {
        for (int i = 0; i < 10; ++i)
        {
            if (i == 4)
            {
                row[i] == -2;
            }
            else
            {
                row[i] = -1;
            }
        }
    }
}

template <const ScoreSheet::Color C>
bool QwintoRow<C>::validate(int index, int value)
{

    index--; //get the array index

    //conditions for wrong place

    if (row[index] != -1)
    {
       // cout<<"br1"<<" "<<row[index]<<"val"<<value<<endl;
        return false;
    }
    if (index != 0)
    {
        for (int i = index - 1; i >= 0; i--)
        {
            if (row[i] > value)
            {
              //  cout<<"br2";
                return false;
            }
        }
    }
    for (int i = index + 1; i < 10; i++)
    {
        if ((row[i]>0) && (row[i] < value))
        {
            // cout<<"br3";
            return false;
        }
    }

    return true;
}
//have to decide how to return nothing if not passing validate
template <const ScoreSheet::Color C>
int &QwintoRow<C>::operator[](int index)
{
    //
    // if (validate(index))
    return row[index]; //guy said no throwing here
    //if cannot insert return -1 for error check
//I know, I inserted validate in other part of code, it works the same
}
//returns true if row is full
template <const ScoreSheet::Color C>
bool QwintoRow<C>::isFull()
{
    int count = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (row[i] > 0)
            count++;//changed WArning! was ++c// why?
    }
    if (count >= 9)
        return true;
    else
        return false;
}
//counts how many numbers in row
template <const ScoreSheet::Color C>
int QwintoRow<C>::amountNums()
{
    int count = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (row[i] > 0)
            ++count;
    }
    return count;
}

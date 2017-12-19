#include <iostream>
#include <string>

using namespace std;

class PlayList
{
  protected:
    struct SongEntry
    {
        string d_artist;
        string d_title;
        SongEntry *d_next;
    };
    int d_size = 0;
    SongEntry *d_list = nullptr;

  public:
    PlayList() = default;
    PlayList(const PlayList &p) : d_size{p.d_size}
    {
        if (this == &p)
        {
            cout << "Why would you do this>?" << endl;
        }
        else
        {
            SongEntry *copy = p.d_list;
            SongEntry *d_list = nullptr;
            SongEntry *dummy = nullptr;
            SongEntry *previous = nullptr;
            while (copy != nullptr)
            {
                string artist = copy->d_artist;
                string title = copy->d_title;
                dummy = new SongEntry{artist, title, nullptr};
                if (d_list == nullptr)
                {
                    d_list = dummy;
                    previous = dummy;
                }
                else
                {
                    previous = new SongEntry{artist, title, previous};
                }
                copy = copy->d_next;
            }
        }
    }
    virtual ~PlayList()
    {
        while (d_list->d_next != nullptr)
        {
            SongEntry *current = d_list;
            d_list = d_list->d_next;
            delete current;
        }
        delete d_list;
    }
    PlayList &operator=(const PlayList &p)
    {
        if (this != &p)
        {
            if (d_list != nullptr)
            {
                SongEntry *current = nullptr;
                while (d_list != nullptr)
                {
                    current = d_list;
                    d_list = d_list->d_next;
                    delete current;
                }
            }
            SongEntry *copy = p.d_list;
            SongEntry *d_list = nullptr;
            SongEntry *dummy = nullptr;
            SongEntry *previous = nullptr;
            while (copy != nullptr)
            {
                string artist = copy->d_artist;
                string title = copy->d_title;
                dummy = new SongEntry{artist, title, nullptr};
                if (d_list == nullptr)
                {
                    d_list = dummy;
                    previous = dummy;
                }
                else
                {
                    previous = new SongEntry{artist, title, previous};
                }
                copy = copy->d_next;
            }
        }
        return *this;
    }
};

class Top5 : public PlayList
{
  public:
    Top5() = default;
    Top5(const Top5 &t) : PlayList{t} {}
    ~Top5() {}
    Top5 &operator=(const Top5 &t)
    {
        if (this != &t)
        {
            PlayList::operator=(t);
        }
        return *this;
    }

    bool append(string artist, string title)
    {
        if (d_size >= 5)
            return false;
        SongEntry *d_tmp = d_list;
        d_list = new SongEntry{artist, title, d_tmp};
        ++d_size;
        return true;
    }

    bool remove()
    {
        if (d_size <= 0)
            return false;
        SongEntry *d_tmp = d_list->d_next;
        delete d_list;
        d_list = d_tmp;
        --d_size;
        return true;
    }
    friend ostream& operator << (ostream& out , const Top5& t){
        SongEntry* s = t.d_list;
        while(s != nullptr){
            string author = s->d_artist;
            string title = s->d_title;
            out << "Autor: "<< author << " title: " << title << endl;
            s = s->d_next; 
        }return out;
    }
};
int main()
{
    Top5 tp;
    tp.append("BROS", "Tell Me");
    tp.append("Dylan Menzie", "Talk To Me");
    tp.append("Blue Rodeo", "I Can't Hide This Anymore");
    tp.append("Sam Roberts Band", "FIEND");
    tp.append("Rag'N'Bone Man", "Human");
    tp.append("Banners", "Into The Storm");
    cout << tp;
    cout << "---------------" << endl;
    Top5 tpCopy{tp};
    tp.remove();
    cout << tp;
    cout << "---------------" << endl;
    cout << tpCopy;
    cout << "---------------" << endl;
    tpCopy = tp;
    cout << tpCopy;
    return 0;
}
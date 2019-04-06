//FAT32 implementation in C++

#include<iostream>
#include<string.h>
#include <ctime>
#include<string.h>
#include<sstream>


using namespace std;

struct File
{
    int size1;
    string name,type,file_time;
    int s_addr;
};

File filenm[20];
File filenm_priority[10];

void disp();

int n=0,n1;
void create(string name,int size1,string type)
{
    int i;
    int p=0;
    int total_size=0;
    time_t now = time(0);
    string file_time = ctime(&now);
    if(size1>4096 || size1<0)
        cout<<"ERROR: Sorry,Can not Handle file of size greater than 4GB"<<"\n";
    else
    {
         for(i=0;i<n;i++)
         {
             if(filenm[i].name==name && filenm[i].type==type)
             {
                cout<<"\n"<<"ERROR: File with same Name and Type already exists, Please change the name or type!"<<"\n"<<"\n";
                p=1;
                break;
             }
         }
        for(i=0;i<n;i++)
        {
            total_size=total_size + filenm[i].size1;
        }
        total_size=total_size + size1;

         if(p==0)
         {
         for(i=n;i>=1;i--)
         {
             filenm[i]=filenm[i-1];
             filenm[i].s_addr=total_size - filenm[i].size1;
             total_size=total_size-filenm[i].size1;
         }

         filenm[0].name=name;
         filenm[0].size1=size1;
         filenm[0].s_addr=0;
         filenm[0].type=type;
         filenm[0].file_time=file_time;
         n++;
         disp();
         cout<<"\n"<<"File Added.."<<"\n"<<"\n";
         }

    }
}
void del(string name)
{
    string type;
    int p=0,i;
    int k[10];
    for(i=0;i<n;i++)
    {
        if(filenm[i].name==name)
        {
            k[p]=i;
            p++;
        }
    }
    if(p==0)
    {
         cout<<"Sorry, No such File Exists!!"<<"\n"<<"\n";
         disp();
    }
    if(p==1)
    {
        int index=k[0];
        for(i=index;i<n-1;i++)
        {
            filenm[i]=filenm[i+1];
        }
        n=n-1;
        disp();
        cout<<"\n"<<"File deleted.."<<"\n"<"\n";

    }
    if(p>1)
    {
        cout<<"There are "<<p<<" Files exist with the same Name,Please give the file type:";
        cin>>type;
        int lm=0;
        for(i=0;i<p;i++)
        {
            int index=k[i];
            cout<<filenm[index].type;
            if(filenm[index].type==type)
            {
                lm++;
                for(i=index;i<n-1;i++)
                {
                    filenm[i]=filenm[i+1];
                }
            n=n-1;
            break;
            }

    }
    if(lm!=0)
    {
        disp();
        cout<<"\n"<<"File deleted.."<<"\n"<"\n";
    }
    if(lm==0)
    {
        cout<<"\n"<<"Sorry no such file Exists!"<<"\n"<<"\n";
        disp();
    }


    }


}
void create_priority(string name,int size1,string type)
{
    int i;
    int p=0;
    int total_size=0;
    if(size1>4096 || size1<0)
        cout<<"ERROR: Sorry,Can not Handle file of size greater than 4GB"<<"\n";
    else
    {
         for(i=0;i<n1;i++)
         {
             if(filenm_priority[i].name==name && filenm_priority[i].type==type)
             {
                cout<<"\n"<<"ERROR: File with same Name and Type already exists, Please change the name or type!"<<"\n"<<"\n";
                p=1;
                break;
             }
         }
        for(i=0;i<n1;i++)
        {
            total_size=total_size + filenm_priority[i].size1;
        }
        total_size=total_size + size1;

         if(p==0)
         {
         for(i=n1;i>=1;i--)
         {
             filenm_priority[i]=filenm_priority[i-1];
             filenm_priority[i].s_addr=total_size - filenm_priority[i].size1;
             total_size=total_size-filenm_priority[i].size1;
         }

         filenm_priority[0].name=name;
         filenm_priority[0].size1=size1;
         filenm_priority[0].s_addr=0;
         filenm_priority[0].type=type;
         n1++;
         cout<<"\n"<<"File Added in priority list.."<<"\n"<<"\n";
         }

    }
}

void defragment()
{
    filenm[0].s_addr=0;
    for(int i=1;i<n;i++)
    {
        filenm[i].s_addr=filenm[i-1].s_addr + filenm[i-1].size1;
    }
    disp();

    cout<<"\n"<<"Defragmentation Successfully completed."<<"\n"<<"\n";
}
void search_file(string name)
{
    int i;
    int ff=0;
    cout<<"\n"<<"Searching in progress..."<<"\n"<<"\n";
    for(i=0;i<n;i++)
    {
        if(filenm[i].name==name)
        {
            ff=1;
            cout<<"| "<<filenm[i].name<<" |"<<"     "<<"| "<<filenm[i].s_addr<<" |"<<"     "<<"| "<<filenm[i].size1<<" |"<<"     "<<"| "<<filenm[i].type<<" |"<<"    "<<filenm[i].file_time<<"\n"<<"\n";


        }
    }
    if(ff==0)
        cout<<"\n"<<"File Not Found"<<"\n"<<"\n";
}

int get_month(string);

void del_file_30(int);
//Little bit complicated
void search_delete()
{
    int i,j;

    // Today's Date
    time_t now = time(0);
    string date_today = ctime(&now);
    string month_today=date_today.substr(4,3);
    string day_today=date_today.substr(8,2);

    int month_today1=get_month(month_today);

    stringstream day_today2(day_today);
    int day_today1;
    day_today2>>day_today1;

    int nmn=0;
    for(i=0;i<n;i++)
    {
        string date_file=filenm[i].file_time;
        string month_file=date_file.substr(4,3);
        string day_file=date_file.substr(8,2);
        int month_file1=get_month(month_file);
        stringstream day_file2(day_file);
        int day_file1;
        day_file2>>day_file1;
        if(month_file1>month_today1)
         {
             del_file_30(i);
             nmn++;
         }
        else
        {
            //Taking no. of days in month as 30
            if(month_file1<month_today1 && day_file1<day_today1)
            {
                del_file_30(i);
                nmn++;
            }
        }
        if(nmn==0)
            cout<<"\n"<<"All files are new.."<<"\n";
        else
            cout<<"\n"<<nmn<<" files deleted"<<"\n";


    }
    disp();
    cout<<"\n";
}

void del_file_30(int index)
{
    int i;
    for(i=index;i<n-1;i++)
        {
            filenm[i]=filenm[i+1];
        }
    n=n-1;
}

int get_month(string month)
{
    int month1;

    if(month=="Jan")
        month1=1;
    if(month=="Feb")
        month1=2;
    if(month=="Mar")
        month1=3;
    if(month=="Apr")
        month1=4;
    if(month=="May")
        month1=5;
    if(month=="Jun")
        month1=6;
    if(month=="Jul")
        month1=7;
    if(month=="Aug")
        month1=8;
    if(month=="Sep")
        month1=9;
    if(month=="Oct")
        month1=10;
    if(month=="Nov")
        month1=11;
    if(month=="Dec")
        month1=12;

    return month1;
}

void disp()
{
    int i;

    cout<<"\n";
    cout<<"********************************* Displaying Application File in the System(FAT 32) *************************************************"<<"\n";
    cout<<"\n"<<"   NAME"<<"     "<<"    S_ADDR"<<"     "<<" SIZE"<<"     "<<" TYPE"<<"     "<<" TIMESTAMP"<<"\n"<<"\n";

   // cout<<"\n"<<"\n"<<"DISPLAYING APPLICATION FILES:"<<"\n";
    for(i=0;i<n;i++)
    {
        cout<<"| "<<filenm[i].name<<" |"<<"    "<<"| "<<filenm[i].s_addr<<" |"<<"     "<<"| "<<filenm[i].size1<<" |"<<"     "<<"| "<<filenm[i].type<<" |"<<"    "<<filenm[i].file_time<<"\n";

    }
    cout<<"\n";

}

void disp_system_files()
{
    int i;
    cout<<"\n";
    cout<<"********************************* Displaying System Files(FAT 32) *************************************************"<<"\n";
    cout<<"\n"<<"   NAME"<<"     "<<"    S_ADDR"<<"     "<<" SIZE"<<"     "<<" TYPE"<<"\n"<<"\n";
    for(i=0;i<n1;i++)
    {
        cout<<"| "<<filenm_priority[i].name<<" |"<<"     "<<"| "<<filenm_priority[i].s_addr<<" |"<<"     "<<"| "<<filenm_priority[i].size1<<" |"<<"     "<<"| "<<filenm_priority[i].type<<" |"<<"\n";

    }
    cout<<"\n";
}

int main()
{
    int i,j,l;
    string name,type;
    int size1;
    int ch=10;
    while(ch!=9)
    {
    cout<<"1. Create a file"<<"\n"<<"2. Delete a file"<<"\n"<<"3. Defragmentation"<<"\n"<<"4. Display the Application Files"<<"\n"<<"5. System File Creation"<<"\n"<<"6. Display System Files"<<"\n"<<"7. Search for a File"<<"\n"<<"8. Deletion of files older than 1 month"<<"\n"<<"9. Exit"<<"\n";
    cout<<"Enter your choice:";
    cin>>ch;
    cout<<"\n";
    switch(ch)
    {
    case 1:
        {
            cout<<"Enter file Name:";
            cin>>name;
            cout<<"Enter File Size:";
            cin>>size1;
            cout<<"Enter File type:";
            cin>>type;
            create(name,size1,type);
            break;
        }
    case 2:
        {
            cout<<"Enter file name which you want to delete:";
            cin>>name;
            del(name);
            break;
        }
    case 3:
        {
            cout<<"Defragmentation in Progress.. Reseting all the addresses!"<<"\n";
            defragment();
            break;
        }
    case 4:
        {
            cout<<"\n"<<"Displaying the Application Files:"<<"\n"<<"\n";
            disp();
            break;
        }
    case 5:
        {
            //SYSTEM FILES AND THE USER CAN NOT DELETE THESE FILES.
            cout<<"Enter file Name:";
            cin>>name;
            cout<<"Enter File Size:";
            cin>>size1;
            cout<<"Enter File type:";
            cin>>type;
            create_priority(name,size1,type);
            break;
        }
    case 6:
        {
            string password,choice1;
            cout<<"\n"<<"Do you Really want to see the System Files[y/n]:";
            cin>>choice1;

            if(choice1=="y" || choice1=="Y'" || choice1=="Yes")
            {
                cout<<"\n"<<"Enter the Password if you want to see the System files:";
                //Here password is admin
                cin>>password;
                if(password=="admin")
                    disp_system_files();
                else
                    cout<<"\n"<<"Invalid Password!"<<"\n"<<"\n";

            }
            break;

        }
    case 7:
        {
            cout<<"Enter the File Name: ";
            cin>>name;
            search_file(name);
            break;
        }
    case 8:
        {
            cout<<"Searching is progress.."<<"\n"<<"\n";
            search_delete();
            break;
        }
    case 9:
        {
            cout<<"Good Bye):";
            break;
        }
    default:
        {
            cout<<"Invalid choice"<<"\n";
        }

    }
    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

   //global variables
    vector<string>tasks;
    vector<int>duration;
    vector<int>priority;
    string username;
    int xpPoints=0;

    //functions
    void addTasks();
    void showTasks();
    void searchTask();
    void showStatistics();
    void bubble();
    void auto_Scheduler();
    void completeTask();
    void xpSystem();

int main()
{
    cout<<"Enter Your Name"<<endl;
    getline(cin,username);
    cout<<"                        "<<endl;
    cout<<"Welcome , "<<username<<"! let is organize your day."<<endl;

    int choice;
    do
    {
    cout<<"                    "<<endl;
    cout<<"=================================================================================="<<endl;
    cout<<"                        "<<username<<" Task Manager"<<endl;
    cout<<"=================================================================================="<<endl;
    cout<<"1. Add Task"<<endl;
    cout<<"2. Show Tasks"<<endl;
    cout<<"3. Search Task"<<endl;
    cout<<"4. Show Statistics"<<endl;
    cout<<"5. Auto Scheduler"<<endl;
    cout<<"6. Complete Task and XP system"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"=================================================================================="<<endl;
    cout<<"Enter Your choice"<<endl;
    cin>>choice;

    switch(choice)
    {
    case 1:
        cout<<"You selected : Add Task"<<endl;
        cout<<"Please enter the task details"<<endl;
        addTasks();
        break;
    case 2:
        cout<<"You selected : Show Tasks"<<endl;
        cout<<"Here are all your current tasks:"<<endl;
        showTasks();
        break;
    case 3:
         cout<<"You selected : Search Tasks"<<endl;
        searchTask();
        break;
    case 4:
        cout<<"You selected : Show Statistics"<<endl;
        cout<<"Here are the statistics of your tasks:"<<endl;
        showStatistics();
        break;
    case 5:
        cout<<"You selected : Auto Scheduler"<<endl;
        auto_Scheduler();
        break;
    case 6:
        cout<<"You selected : Complete Task and XP System"<<endl;
        cout<<"Here are all your current tasks:"<<endl;
        completeTask();
        xpSystem();
        break;
    case 0:
        cout<<"Exiting program Goodbye"<<endl;
        break;
    default:
        cout<<"Invalid choice,please try again"<<endl;
    }
    }
    while(choice!=0);

    return 0;
}
void addTasks()
{
    int taskcount=0;
    string taskName;
    int taskDuration=0;
    int taskPriority=0;
    cout<<"How many tasks do you want to plan today?"<<endl;
    cin>>taskcount;

    for(int i=0;i<taskcount;i++)
    {
          cout<<"Enter Name of task "<<i+1<<endl;

          //to empty buffer
          cin.ignore();

          getline(cin,taskName);
          tasks.push_back(taskName);

          cout<<"Enter duration(minitus) of task "<<i+1<<endl;
          cin>>taskDuration;
          duration.push_back(taskDuration);

          //Note : Smaller priority number=higher importance
          cout<<"Enter priority of task "<<i+1<<endl;
          cin>>taskPriority;
          priority.push_back(taskPriority);
    }
     cout<<"Task added successfully ! Keep going "<<username<<endl;
}

void showTasks()
{
    for(int i=0;i<tasks.size();i++)
    {
         cout<<"Task "<<i+1<<" is "<<tasks[i]<<endl;
         cout<<"Duration of task "<<i+1<<" in minutes is "<<duration[i]<<endl;
         cout<<"Priority of task "<<i+1<<" is "<<priority[i]<<endl;
    }

}

void searchTask()
{
    int i=0;
    bool found=0;
    string task;
    cout<<"Enter Name of the task you are looking for"<<endl;
    cin.ignore();
    getline(cin,task);
    for( i=0;i<tasks.size();i++)
    {
        if(tasks[i]==task)
        {
            found=1;
            break;
        }
    }

    if(found)
    {
        cout<<"Task is found"<<endl;
        cout<<"Name of task "<<i+1<<" is "<<tasks[i]<<endl;
        cout<<"Duration of task "<<i+1<<" in minutes is "<<duration[i]<<endl;
        cout<<"Priority of task "<<i+1<<" is "<<priority[i]<<endl;
    }

    else
    {
        cout<<"Task not found"<<endl;
    }
}

void showStatistics()
{
    int sum=0;
    cout<<"The number of total tasks = "<<tasks.size()<<endl;
    for(int i=0;i<duration.size();i++)
    {
        sum+=duration[i];
    }
    cout<<"The total time in minutes for all tasks = "<<sum<<endl;
}

void bubble()
{
    for(int itr=0;itr<priority.size();itr++)
    {
        for(int i=0;i<(priority.size()-1);i++)
        {
            if(priority[i+1]<priority[i])
            {
                swap(priority[i+1],priority[i]);
                swap(tasks[i+1],tasks[i]);
                swap(duration[i+1],duration[i]);
            }

        }
    }


}

/*
void auto_Scheduler()
{
    bubble();
    cout<<"The proposed schedule in order priority is:"<<endl;
    for(int i=0;i<priority.size();i++)
    {
       cout<<i+1<<":"<<tasks[i]<<" (Priority "<<priority[i]<<" ,Duration "<<duration[i]<<" minutes) "<<endl;

    }
}
*/

void auto_Scheduler()
{
    bubble();
    cout<<"The proposed schedule in order priority is:"<<endl;
    //print address of schedule
    cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<left<< setw(10) <<"Number"<< setw(20) <<"Task"<< setw(10)<<"Priority"<<setw(10)<<"Duration"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;
    //print tasks in schedule
    for(int i=0;i<priority.size();i++)
    {
       cout<<left<< setw(10) <<i+1<< setw(20) <<tasks[i]<< setw(10) <<priority[i]<< setw(10) <<duration[i]<<endl;

    }
}

void completeTask()
{
    int Number;
    //Show all tasks by their numbers
    for(int i=0;i<tasks.size();i++)
    {
        cout<<i+1<<":"<<tasks[i]<<endl;
    }
    cout<<"Enter the number of the completed task "<<endl;
    cin>>Number;
    //Check if the entered number is vaild
    if(Number>=1 and Number<=tasks.size())
   {
       int index=Number-1; //because number start from 1 but index start from 0

       if(duration[index]>60)
       {
           xpPoints+=20;
       }
       else
       {
           xpPoints+=10;
       }
       if(priority[index]==1)
       {
           xpPoints+=10; //Bonus
       }

       cout<<"Great "<<username<<" ! You completed a task "<<Number<<" and earned "<<xpPoints<<" XP "<<endl;

       //remove completed task
       tasks.erase(tasks.begin()+index);
       duration.erase(duration.begin()+index);
       priority.erase(priority.begin()+index);
   }
    else
    {
        cout<<"invalid task number"<<endl;
    }

}
void xpSystem()
{
    cout<<"Your total XP is : "<<xpPoints<<endl;
    if(xpPoints<30)
    {
        cout<<"Great start "<<username<<" ! Keep going"<<endl;
    }
     else if(xpPoints<60)
     {
         cout<<"Awesome "<<username<<" ! You are making real progress! "<<endl;
     }
      else if(xpPoints<100)
      {
          cout<<"Fantastic "<<username<<" ! You are unstoppable!"<<endl;
      }
      else
      {
          cout<<"Legendary "<<username<<" ! You are a productivity master!"<<endl;
      }
}

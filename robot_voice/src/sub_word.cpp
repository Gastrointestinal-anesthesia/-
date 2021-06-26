#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ros/ros.h>
#include <std_msgs/String.h> 
#include <fstream>
#include <sstream>
#include "qtts.h"
#include "msp_cmn.h"
#include "msp_errors.h"


using namespace std;
ifstream inFile;
int openFlag = 0;
ros::Publisher pub;
std_msgs::String msg1;



void callback(const std_msgs::String::ConstPtr& msg)
{
    string str1 = msg->data.c_str();
    string str2 = "打开界面。";

    if(str1 == str2)
    {
        inFile.open("//home//lab129//test_ws//src", ios::in);
        cout << "ok" << endl;
        string s1("好的,打开界面");
        msg1.data = s1.data();
        pub.publish(msg1);
        ros::spinOnce();
        sleep(1);
    }  
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "sub_word");
    ros::NodeHandle n;
    pub= n.advertise<std_msgs::String>("/voice/xf_tts_topic",1000);
    ros::Subscriber sub = n.subscribe("voiceWords",10,callback);
    cout<<"您好！你可以语音控制啦！"<<endl;
    ros::spin();
}



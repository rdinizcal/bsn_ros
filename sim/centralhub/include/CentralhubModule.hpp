#ifndef CENTRALHUB_MODULE_HPP
#define CENTRALHUB_MODULE_HPP

#include <fstream>
#include <chrono>

#include "ros/ros.h"

#include "bsn/processor/Processor.hpp"
#include "bsn/communication/TCPSend.hpp"

// #include "bsn/msg/info/TaskInfo.h"
#include "bsn/msg/data/SensorData.h"
// #include "bsn/msg/info/ContextInfo.hpp"
// #include "bsn/msg/info/MonitorTaskInfo.hpp"
#include "bsn/SensorData.h"
// #include "bsn/msg/control/CentralHubControlCommand.hpp"



class CentralhubModule {
    private:
        CentralhubModule(const CentralhubModule & /*obj*/);
        CentralhubModule &operator=(const CentralhubModule & /*obj*/);
        virtual void tearDown();   

		void sendTaskInfo(const std::string &/*task_id*/, const double &/*cost*/, const double &/*reliability*/, const double &/*frequency*/);
		
        void sendMonitorTaskInfo(const std::string &/*task_id*/, const double &/*cost*/, const double &/*reliability*/, const double &/*frequency*/);

        void receiveSensorData(const bsn::SensorData::ConstPtr&);


    public:
        void setUp();
        CentralhubModule(const int32_t &argc, char **argv);
        virtual ~CentralhubModule();

        void run();

    private:
        bool active;
		std::map<std::string,double> params;

        uint32_t connect;
        uint32_t port;
        std::string ip;
        
        uint32_t persist;
        std::ofstream fp;
        std::string path;

        std::array<double, 5> data;
        std::vector<std::list<double>> data_list;
        double patient_status;
};

#endif 
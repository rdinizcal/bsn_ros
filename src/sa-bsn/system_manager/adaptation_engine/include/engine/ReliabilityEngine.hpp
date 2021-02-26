#ifndef COSTENGINE_HPP
#define COSTENGINE_HPP

#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

#include "ros/ros.h"
#include "ros/package.h"

#include "libbsn/goalmodel/Node.hpp"
#include "libbsn/goalmodel/Goal.hpp"
#include "libbsn/goalmodel/Task.hpp"
#include "libbsn/goalmodel/Property.hpp"
#include "libbsn/goalmodel/LeafTask.hpp"
#include "libbsn/goalmodel/Context.hpp"
#include "libbsn/goalmodel/GoalTree.hpp"
#include "libbsn/model/Formula.hpp"
#include "libbsn/utils/utils.hpp"

#include "lepton/Lepton.h"

#include "archlib/DataAccessRequest.h"
#include "archlib/Strategy.h"
#include "archlib/Exception.h"
#include "archlib/EnergyStatus.h"
#include "archlib/ROSComponent.hpp"
#include "archlib/EngineRequest.h"


class ReliabilityEngine : public arch::ROSComponent {
	
	public: 
		ReliabilityEngine(int &argc, char **argv, std::string name);
    	virtual ~ReliabilityEngine();

    private:
      	ReliabilityEngine(const ReliabilityEngine &);
    	ReliabilityEngine &operator=(const ReliabilityEngine &);

  	public:
        virtual void setUp();
    	virtual void tearDown();
		virtual void body();

		void setUp_formula(std::string formula);
		void receiveException(const archlib::Exception::ConstPtr& msg);

		void monitor();
    	void analyze();
		void plan();
    	void execute();

		bool sendAdaptationParameter(archlib::EngineRequest::Request &req, archlib::EngineRequest::Response &res);

  	private:
	  double calculate_qos(bsn::model::Formula, std::map<std::string, double>);
	  bool blacklisted(std::map<std::string,double> &);

	private:
		double c_ref;
		double offset;
		double Kp;
		double info_quant;
		double monitor_freq;
		double actuation_freq;
		double stability_margin;
		std::string qos_attribute;

		bsn::model::Formula target_system_model;
		std::map<std::string, double> strategy;
		std::map<std::string, int> priority;
		std::map<std::string, int> deactivatedComponents;

		ros::NodeHandle handle;
		ros::Publisher enact;
		ros::Publisher energy_status;
		ros::ServiceServer enactor_server;

		int cycles;
		int counter;
};

#endif 
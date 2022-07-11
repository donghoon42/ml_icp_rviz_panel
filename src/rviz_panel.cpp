#include "rviz-panel/rviz_panel.hpp"
#include <pluginlib/class_list_macros.hpp>


PLUGINLIB_EXPORT_CLASS(rviz_panel::simplePanel, rviz::Panel)

PLUGINLIB_EXPORT_CLASS(rviz_panel::test_Panel, rviz::Panel)

namespace rviz_panel
{
    simplePanel::simplePanel(QWidget * parent)
    :   rviz::Panel(parent),
        ui_(std::make_shared<Ui::two_button>())
    {
        // Extend the widget with all attributes and children from UI file
        ui_->setupUi(this);

        // Define ROS publisher
        button_1_pub_ = nh_.advertise<std_msgs::Bool>("button_1_topic", 1);
        button_2_pub_ = nh_.advertise<std_msgs::Bool>("button_2_topic", 1);

        // Declare ROS msg_
        msg_.data = true;

        connect(ui_->pushButton_1, SIGNAL(clicked()), this, SLOT(button_one()));
        connect(ui_->pushButton_2, SIGNAL(clicked()), this, SLOT(button_two()));
    }


    void simplePanel::button_one()
    {
        ROS_INFO_STREAM("Button one pressed.");
        this->button_1_pub_.publish(this->msg_);
    }


    void simplePanel::button_two()
    {
        ROS_INFO_STREAM("Button two pressed.");
        this->button_2_pub_.publish(this->msg_);
    }


    /**
     *  Save all configuration data from this panel to the given
     *  Config object. It is important here that you call save()
     *  on the parent class so the class id and panel name get saved.
     */
    void simplePanel::save(rviz::Config config) const
    {
        rviz::Panel::save(config);
    }

    /**
     *  Load all configuration data for this panel from the given Config object.
     */
    void simplePanel::load(const rviz::Config & config)
    {
        rviz::Panel::load(config);
    }


    test_Panel::test_Panel(QWidget * parent)
    :   rviz::Panel(parent),
        ui_(std::make_shared<Ui::two_button>())
    {
        // Extend the widget with all attributes and children from UI file
        ui_->setupUi(this);

        // Define ROS publisher
        button_1_pub_ = nh_.advertise<std_msgs::Int64>("button_1_topic", 1);

        // Declare ROS msg_
        msg_.data = 0;

        connect(ui_->pushButton_1, SIGNAL(clicked()), this, SLOT(button_one()));
        connect(ui_->pushButton_2, SIGNAL(clicked()), this, SLOT(button_two()));
        connect(ui_->pushButton_3, SIGNAL(clicked()), this, SLOT(button_three()));
        connect(ui_->pushButton_4, SIGNAL(clicked()), this, SLOT(button_four()));

        connect(ui_->pushButton_posX, SIGNAL(clicked()), this, SLOT(button_posX()));
        connect(ui_->pushButton_negX, SIGNAL(clicked()), this, SLOT(button_negX()));
        connect(ui_->pushButton_posY, SIGNAL(clicked()), this, SLOT(button_posY()));
        connect(ui_->pushButton_negY, SIGNAL(clicked()), this, SLOT(button_negY()));
        connect(ui_->pushButton_posZ, SIGNAL(clicked()), this, SLOT(button_posZ()));
        connect(ui_->pushButton_negZ, SIGNAL(clicked()), this, SLOT(button_negZ()));
        connect(ui_->pushButton_CCW, SIGNAL(clicked()), this, SLOT(button_CCW()));
        connect(ui_->pushButton_CW, SIGNAL(clicked()), this, SLOT(button_CW()));
        connect(ui_->pushButton_RUN, SIGNAL(clicked()), this, SLOT(button_RUN()));
    }


    void test_Panel::button_one()
    {
        msg_.data = 114;
        ROS_INFO_STREAM("Button one pressed. "<< msg_.data);
        this->button_1_pub_.publish(this->msg_);
    }
    void test_Panel::button_two()
    {
        msg_.data = 99;
        ROS_INFO_STREAM("Button two pressed.");
        this->button_1_pub_.publish(this->msg_);
    }
    void test_Panel::button_three()
    {
        msg_.data = 32;
        ROS_INFO_STREAM("Button three pressed.");
        this->button_1_pub_.publish(this->msg_);
    }
    void test_Panel::button_four()
    {
        msg_.data = 103;
        ROS_INFO_STREAM("Button four pressed.");
        this->button_1_pub_.publish(this->msg_);
    }


    void test_Panel::button_posX()
    {
        msg_.data = 119;
        this->button_1_pub_.publish(this->msg_);
    }
    void test_Panel::button_negX()
    {
        msg_.data = 115;
        this->button_1_pub_.publish(this->msg_);
    }
    void test_Panel::button_posY()
    {
        msg_.data = 97;
        this->button_1_pub_.publish(this->msg_);
    }
    void test_Panel::button_negY()
    {
        msg_.data = 100;
        this->button_1_pub_.publish(this->msg_);
    }
    void test_Panel::button_posZ()
    {
        msg_.data = 113;
        this->button_1_pub_.publish(this->msg_);
    }
    void test_Panel::button_negZ()
    {
        msg_.data = 101;
        this->button_1_pub_.publish(this->msg_);
    }
    void test_Panel::button_CCW()
    {
        msg_.data = 122;
        this->button_1_pub_.publish(this->msg_);
    }
    void test_Panel::button_CW()
    {
        msg_.data = 120;
        this->button_1_pub_.publish(this->msg_);
    }
    void test_Panel::button_RUN()
    {
        msg_.data = 105;
        this->button_1_pub_.publish(this->msg_);
    }
    /**
     *  Save all configuration data from this panel to the given
     *  Config object. It is important here that you call save()
     *  on the parent class so the class id and panel name get saved.
     */
    void test_Panel::save(rviz::Config config) const
    {
        rviz::Panel::save(config);
    }

    /**
     *  Load all configuration data for this panel from the given Config object.
     */
    void test_Panel::load(const rviz::Config & config)
    {
        rviz::Panel::load(config);
    }
} // namespace rviz_panel

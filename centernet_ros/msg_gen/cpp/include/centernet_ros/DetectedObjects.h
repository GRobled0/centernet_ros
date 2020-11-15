/* Auto-generated by genmsg_cpp for file /home/guillermo/anaconda3/envs/CenterNet/CenterNet/src/ROS/src/centernet_ros/msg/DetectedObjects.msg */
#ifndef CENTERNET_ROS_MESSAGE_DETECTEDOBJECTS_H
#define CENTERNET_ROS_MESSAGE_DETECTEDOBJECTS_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "std_msgs/Header.h"
#include "centernet_ros/ObjectInfo.h"

namespace centernet_ros
{
template <class ContainerAllocator>
struct DetectedObjects_ {
  typedef DetectedObjects_<ContainerAllocator> Type;

  DetectedObjects_()
  : header()
  , objects()
  {
  }

  DetectedObjects_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , objects(_alloc)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef std::vector< ::centernet_ros::ObjectInfo_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::centernet_ros::ObjectInfo_<ContainerAllocator> >::other >  _objects_type;
  std::vector< ::centernet_ros::ObjectInfo_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::centernet_ros::ObjectInfo_<ContainerAllocator> >::other >  objects;


  typedef boost::shared_ptr< ::centernet_ros::DetectedObjects_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::centernet_ros::DetectedObjects_<ContainerAllocator>  const> ConstPtr;
}; // struct DetectedObjects
typedef  ::centernet_ros::DetectedObjects_<std::allocator<void> > DetectedObjects;

typedef boost::shared_ptr< ::centernet_ros::DetectedObjects> DetectedObjectsPtr;
typedef boost::shared_ptr< ::centernet_ros::DetectedObjects const> DetectedObjectsConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::centernet_ros::DetectedObjects_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::centernet_ros::DetectedObjects_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace centernet_ros

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::centernet_ros::DetectedObjects_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::centernet_ros::DetectedObjects_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::centernet_ros::DetectedObjects_<ContainerAllocator> > {
  static const char* value() 
  {
    return "a74ced4691e2f209ce4fbe3dd6d24c31";
  }

  static const char* value(const  ::centernet_ros::DetectedObjects_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xa74ced4691e2f209ULL;
  static const uint64_t static_value2 = 0xce4fbe3dd6d24c31ULL;
};

template<class ContainerAllocator>
struct DataType< ::centernet_ros::DetectedObjects_<ContainerAllocator> > {
  static const char* value() 
  {
    return "centernet_ros/DetectedObjects";
  }

  static const char* value(const  ::centernet_ros::DetectedObjects_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::centernet_ros::DetectedObjects_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
ObjectInfo[] objects\n\
\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: centernet_ros/ObjectInfo\n\
string type\n\
float32 prob\n\
int32 tl_x\n\
int32 tl_y\n\
int32 width\n\
int32 height\n\
\n\
";
  }

  static const char* value(const  ::centernet_ros::DetectedObjects_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::centernet_ros::DetectedObjects_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::centernet_ros::DetectedObjects_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::centernet_ros::DetectedObjects_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.objects);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER
}; // struct DetectedObjects_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::centernet_ros::DetectedObjects_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::centernet_ros::DetectedObjects_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "objects[]" << std::endl;
    for (size_t i = 0; i < v.objects.size(); ++i)
    {
      s << indent << "  objects[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::centernet_ros::ObjectInfo_<ContainerAllocator> >::stream(s, indent + "    ", v.objects[i]);
    }
  }
};


} // namespace message_operations
} // namespace ros

#endif // CENTERNET_ROS_MESSAGE_DETECTEDOBJECTS_H


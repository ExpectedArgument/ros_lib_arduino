#ifndef _ROS_SERVICE_SetObjectState_h
#define _ROS_SERVICE_SetObjectState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hector_worldmodel_msgs/ObjectState.h"

namespace hector_worldmodel_msgs
{

static const char SETOBJECTSTATE[] = "hector_worldmodel_msgs/SetObjectState";

  class SetObjectStateRequest : public ros::Msg
  {
    public:
      typedef const char* _object_id_type;
      _object_id_type object_id;
      typedef hector_worldmodel_msgs::ObjectState _new_state_type;
      _new_state_type new_state;

    SetObjectStateRequest():
      object_id(""),
      new_state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_object_id = strlen(this->object_id);
      varToArr(outbuffer + offset, length_object_id);
      offset += 4;
      memcpy(outbuffer + offset, this->object_id, length_object_id);
      offset += length_object_id;
      offset += this->new_state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_object_id;
      arrToVar(length_object_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_object_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_object_id-1]=0;
      this->object_id = (char *)(inbuffer + offset-1);
      offset += length_object_id;
      offset += this->new_state.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETOBJECTSTATE; };
    const char * getMD5(){ return "f1ca4bb9d91ddc88e48d16dceb6ab0e5"; };

  };

  class SetObjectStateResponse : public ros::Msg
  {
    public:

    SetObjectStateResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SETOBJECTSTATE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetObjectState {
    public:
    typedef SetObjectStateRequest Request;
    typedef SetObjectStateResponse Response;
  };

}
#endif

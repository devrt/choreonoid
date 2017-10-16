/**
   \file
   \author Shin'ichiro Nakaoka
*/

#include "ContactMaterial.h"

using namespace cnoid;


ContactMaterial::ContactMaterial()
{
    info_ = new Mapping;
}


ContactMaterial::ContactMaterial(const ContactMaterial& org)
{
    info_ = org.info_->cloneMapping();
}


ContactMaterial::ContactMaterial(const Mapping* info)
{
    info_ = info->cloneMapping();

    if(info_->extract("friction"), staticFriction_){
        dynamicFriction_ = staticFriction_;
    }
    info_->extract("staticFriction", staticFriction_);
    info_->extract("dynamicFriction", dynamicFriction_);

    info_->extract("restitution", restitution_);
}


ContactMaterial::~ContactMaterial()
{

}


template<> double ContactMaterial::info(const std::string& key, const double& defaultValue) const
{
    double value;
    if(info_->read(key, value)){
        return value;
    }
    return defaultValue;
}


template<> bool ContactMaterial::info(const std::string& key, const bool& defaultValue) const
{
    bool value;
    if(info_->read(key, value)){
        return value;
    }
    return defaultValue;
}

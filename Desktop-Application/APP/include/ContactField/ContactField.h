//
// Created by shalaga44 on 1/5/21.
//

#ifndef DESKTOP_APPLICATION_CONTACTFIELD_H
#define DESKTOP_APPLICATION_CONTACTFIELD_H
using namespace std;

class ContactField {
private:
    string name;
    bool hasMultipleValues = false;
public:
    explicit ContactField(string name, bool hasMultipleValues);

    explicit ContactField(string name);
    string getDBName();
};


static const ContactField CONTACT_FIELD_NAME = ContactField("Name");
static const ContactField CONTACT_FIELD_GIVEN_NAME = ContactField("Given Name");
static const ContactField CONTACT_FIELD_ADDITIONAL_NAME = ContactField("Additional Name");
static const ContactField CONTACT_FIELD_FAMILY_NAME = ContactField("Family Name");

static const ContactField CONTACT_FIELD_YOMI_NAME = ContactField("Yomi Name");
static const ContactField CONTACT_FIELD_GIVEN_NAME_YOMI = ContactField("Given Name Yomi");
static const ContactField CONTACT_FIELD_ADDITIONAL_NAME_YOMI = ContactField("Additional Name Yomi");
static const ContactField CONTACT_FIELD_FAMILY_NAME_YOMI = ContactField("Family Name Yomi");

static const ContactField CONTACT_FIELD_NAME_PREFIX = ContactField("Name Prefix");
static const ContactField CONTACT_FIELD_NAME_SUFFIX = ContactField("Name Suffix");
static const ContactField CONTACT_FIELD_INITIALS = ContactField("Initials");
static const ContactField CONTACT_FIELD_NICKNAME = ContactField("Nickname");
static const ContactField CONTACT_FIELD_SHORT_NAME = ContactField("Short Name");
static const ContactField CONTACT_FIELD_MAIDEN_NAME = ContactField("Maiden Name");

static const ContactField CONTACT_FIELD_BIRTHDAY = ContactField("Birthday");
static const ContactField CONTACT_FIELD_GENDER = ContactField("Gender");
static const ContactField CONTACT_FIELD_LOCATION = ContactField("Location");
static const ContactField CONTACT_FIELD_BILLING_INFORMATION = ContactField("Billing Information");
static const ContactField CONTACT_FIELD_DIRECTORY_SERVER = ContactField("Directory Server");
static const ContactField CONTACT_FIELD_MILEAGE = ContactField("Mileage");
static const ContactField CONTACT_FIELD_OCCUPATION = ContactField("Occupation");
static const ContactField CONTACT_FIELD_HOBBY = ContactField("Hobby");
static const ContactField CONTACT_FIELD_SENSITIVITY = ContactField("Sensitivity");
static const ContactField CONTACT_FIELD_PRIORITY = ContactField("Priority");
static const ContactField CONTACT_FIELD_SUBJECT = ContactField("Subject");
static const ContactField CONTACT_FIELD_NOTES = ContactField("Notes");
static const ContactField CONTACT_FIELD_LANGUAGE = ContactField("Language");
static const ContactField CONTACT_FIELD_PHOTO = ContactField("Photo");
static const ContactField CONTACT_FIELD_GROUP_MEMBERSHIP = ContactField("Group Membership");

static const ContactField CONTACT_FIELD_EMAIL = ContactField("E-mail", true);
static const ContactField CONTACT_FIELD_PHONE = ContactField("phone", true);
static const ContactField CONTACT_FIELD_ORGANIZATION = ContactField("Organization", true);
static const ContactField CONTACT_FIELD_WEBSITE = ContactField("Website", true);


#endif //DESKTOP_APPLICATION_CONTACTFIELD_H

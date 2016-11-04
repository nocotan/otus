/**
 * @file fields.hpp
 * @brief this file implements the extension fields.
 * @author nocotan
 * @date 2016/11/4
 */
#ifndef FIELDS_HPP
#define FIELDS_HPP

#include <string>

namespace otus_field {
    class ExtAbstractField {

        private:

            //! Null flag
            bool null_flag = false;

            //! input field name
            std::string fieldname = null;

        public:

            /**
             * @fn
             * Constructor
             */
            ExtAbstractField() { }

            /**
             * @fn
             * Null flag setter
             */
            void set_null_flag(bool null_flag) {
                this->null_flag = null_flag;
            }

            /**
             * @fn fieldname setter
             */
            void set_fieldname(std::string fieldname) {
                this->filename = fieldname;
            }

            /**
             * @fn
             * fieldvalue setter
             */
            virtual void set_fieldvalue(std::string fieldvalue) = 0;
    };


    class ExtNumberField : public ExtAbstractField {

        private:

            //! number minimum size
            int min_value = 0;

            //! number max size
            int max_value = 65535;

            //! field value
            std::string fieldvalue = nullptr;

        public:

            /**
             * @fn
             * Constructor
             * @param (fieldvalue) field value
             */
            ExtNumberField(std::string fieldvalue) {
                set_fieldvalue(fieldvalue);
            }

            /**
             * @fn
             * Constructor
             * @param (fieldvalue) field value
             */
            ExtNumberField(int fieldvalue) {
                set_fieldvalue(fieldvalue);
            }

            /**
             * @fn
             * fieldvalue setter
             * @param (fieldvalue) fieldvalue
             */
            void set_fieldvalue(std::string fieldvalue) {
                if (fieldvalue != nullptr) {
                    this->fieldvalue = fieldvalue;
                }
            };

            /**
             * @fn
             * fieldvalue setter
             * @param (fieldvalue) field value
             */
            void set_fieldvalue(int fieldvalue) {
                this->fieldvalue = to_string(fieldvalue);
            }

            /**
             * @fn
             * fieldvalue getter
             */
            const int get_fieldvalue() const {
                return std::stoi(this->fieldvalue);
            }

            /**
             * @fn
             * fieldvalue getter
             */
            const int get_fieldvalue_as_string() const {
                return this->fieldvalue;
            }

            /**
             * @fn
             * min_value getter
             */
            const int get_min_value() const {
                return this->min_value;
            }

            /**
             * @fn
             * max_value getter
             */
            const int get_max_value() const {
                return this->max_value;
            }
    };
}

#endif

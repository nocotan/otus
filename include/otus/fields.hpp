/**
 * @file fields.hpp
 * @brief this file implements the extension fields.
 * @author nocotan
 * @date 2016/11/4
 */
#ifndef FIELDS_HPP
#define FIELDS_HPP

#include <limits.h>
#include <string>

namespace otus_field {
    class ExtAbstractField {

        private:

            //! empty flag
            bool empty_flag = false;

            //! input field name
            std::string fieldname = "";

        public:

            /**
             * @fn
             * Constructor
             */
            ExtAbstractField() { }

            /**
             * @fn
             * empty flag setter
             */
            void set_empty_flag(bool empty_flag) {
                this->empty_flag = empty_flag;
            }

            /**
             * @fn fieldname setter
             */
            void set_fieldname(std::string fieldname) {
                this->fieldname = fieldname;
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
            int min_value = std::numeric_limits<int>::min();

            //! number max size
            int max_value = std::numeric_limits<int>::max();

            //! field value
            std::string fieldvalue = "";

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
                if (fieldvalue != "") {
                    this->fieldvalue = fieldvalue;
                }
            };

            /**
             * @fn
             * fieldvalue setter
             * @param (fieldvalue) field value
             */
            void set_fieldvalue(int fieldvalue) {
                this->fieldvalue = std::to_string(fieldvalue);
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
            const std::string get_fieldvalue_as_string() const {
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

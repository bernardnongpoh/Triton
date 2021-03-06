//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the BSD License.
*/

#include <cstdlib>

#include <solverModel.hpp>
#include <symbolicVariable.hpp>



namespace triton {
  namespace engines {
    namespace solver {

      SolverModel::SolverModel() {
        this->name  = "";
        this->id    = -1;
        this->value = 0;
      }


      SolverModel::SolverModel(const std::string& name, triton::uint512 value) {
        this->name  = name;
        this->id    = std::atoi(name.c_str() + TRITON_SYMVAR_NAME_SIZE);
        this->value = value;
      }


      SolverModel::SolverModel(const SolverModel& other) {
        this->copy(other);
      }


      void SolverModel::copy(const SolverModel& other) {
        this->name  = other.name;
        this->id    = other.id;
        this->value = other.value;
      }


      SolverModel::~SolverModel() {
      }


      const std::string& SolverModel::getName(void) const {
        return this->name;
      }


      triton::uint32 SolverModel::getId(void) const {
        return this->id;
      }


      triton::uint512 SolverModel::getValue(void) const {
        return this->value;
      }


      void SolverModel::operator=(const SolverModel& other) {
        this->copy(other);
      }


      std::ostream& operator<<(std::ostream& stream, const SolverModel& model) {
        stream << model.getName() << " = " << std::hex << model.getValue() << std::dec;
        return stream;
      }


      std::ostream& operator<<(std::ostream& stream, const SolverModel* model) {
        stream << *model;
        return stream;
      }

    };
  };
};

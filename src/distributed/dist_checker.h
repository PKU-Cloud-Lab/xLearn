//------------------------------------------------------------------------------
// Copyright (c) 2016 by contributors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//------------------------------------------------------------------------------

/*
Author: Chao Ma (mctt90@gmail.com)

This file defines the Checker class, which can check and parse
the command line arguments.
*/

#ifndef XLEARN_DISTRIBUTED_DIST_CHECKER_H_
#define XLEARN_DISTRIBUTED_DIST_CHECKER_H_

#include <vector>
#include <string>

#include "src/base/common.h"
#include "src/data/hyper_parameters.h"

namespace xLearn {

typedef std::vector<std::string> StringList;

//------------------------------------------------------------------------------
// Checker is used to check and parse command line arguments for xLearn.
//------------------------------------------------------------------------------
class DistChecker {
 public:
  // Constructor and Destructor
  DistChecker() { }
  ~DistChecker() { }

  // Initialize Checker
  void Initialize(bool is_train, int argc, char* argv[]);

  // Check and parse arguments
  bool check_cmd(HyperParam& hyper_param);

  // Check hyper-param. Used by c_api
  bool check_param(HyperParam& hyper_param);

 protected:
  /* Store all the possible options */
  StringList menu_;
  /* User input command line */
  StringList args_;
  /* train or predict */
  bool is_train_;

  // Print the help menu
  std::string option_help() const;

  // Check options for training and prediction
  bool check_train_options(HyperParam& hyper_param);
  bool check_train_param(HyperParam& hyper_param);
  bool check_prediction_options(HyperParam& hyper_param);
  bool check_prediction_param(HyperParam& hyper_param);
  void check_conflict_train(HyperParam& hyper_param);
  void check_conflict_predict(HyperParam& hyper_param);
  
 private:
  DISALLOW_COPY_AND_ASSIGN(DistChecker);
};

} // namespace xLearn

#endif // XLEARN_DISTRIBUTED_DIST_CHECKER_H_

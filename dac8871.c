/*
Copyright 2019 Owen Lyke

Permission is hereby granted, free of charge, to any person obtaining a copy of this 
software and associated documentation files (the "Software"), to deal in the Software 
without restriction, including without limitation the rights to use, copy, modify, 
merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit 
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be 
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "dac8871.h"

dac8871_status_e dac8871_init_dev(dac8871_dev_t* pdev, dac8871_if_t* pif, void* arg){
  if(pdev == NULL)          { return DAC8871_STAT_ERR_INVALID_ARG; }
  if(pif == NULL)           { return DAC8871_STAT_ERR_INVALID_ARG; }
  pdev->_if = pif;
  pdev->_arg = arg;
  if(pdev->_if->set_ldac != NULL){ pdev->_if->set_ldac(false, pdev->_arg); } // set LDAC low so that code writes are automatically latched in
  return DAC8871_STAT_OK;
}

dac8871_status_e dac8871_set_code(dac8871_dev_t* pdev, uint16_t code){
  if(pdev == NULL){ return DAC8871_STAT_ERR_INVALID_ARG; }
  if(pdev->_if == NULL){ return DAC8871_STAT_ERR_INVALID_ARG; }
  dac8871_status_e retval = DAC8871_STAT_OK;
  retval |= pdev->_if->write_16b(code, pdev->_arg);
  return retval;
}
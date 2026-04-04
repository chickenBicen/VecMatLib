//
// Created by chice on 4/3/2026.
//

#ifndef VECMATLIB_ASSERT_H
#define VECMATLIB_ASSERT_H

// Assert.h
#pragma once

#include <cstdlib>
#include <iostream>

#define MY_ASSERT(cond, msg)                            \
  do {                                                  \
    if (!(cond)) {                                      \
      std::cerr << "Assertion failed: " << msg << "\n"; \
      std::abort();                                     \
    }                                                   \
  } while (false)

#endif  // VECMATLIB_ASSERT_H

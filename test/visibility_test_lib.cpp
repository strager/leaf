// Copyright (c) 2018-2021 Emil Dotchevski and Reverge Studios, Inc.

// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "visibility_test_lib.hpp"
#include <boost/leaf/exception.hpp>
#include <boost/leaf/on_error.hpp>

#if defined(VISIBILITY_TEST_LIB_DYN_LINK)
#	define EXPORT BOOST_SYMBOL_EXPORT
#else
#	define EXPORT
#endif

namespace leaf = boost::leaf;

leaf::result<void> EXPORT hidden_result()
{
	auto load = leaf::on_error( my_info<1>{1}, my_info<3>{3} );
	return leaf::new_error( my_info<2>{2} );
}

#ifndef BOOST_NO_EXCEPTIONS

leaf::result<void> EXPORT hidden_throw()
{
	auto load = leaf::on_error( my_info<1>{1}, my_info<3>{3} );
	throw leaf::exception( my_info<2>{2} );
}

#endif

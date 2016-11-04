#ifndef BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_MODIFIER_DESTINATION_HPP_20100624
#define BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_MODIFIER_DESTINATION_HPP_20100624

// Copyright 2010 (C) Dean Michael Berris
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/network/protocol/http/support/client_or_server.hpp>
#include <boost/network/support/pod_or_normal.hpp>
#include <boost/network/support/is_async.hpp>
#include <boost/thread/future.hpp>
#include <boost/concept/requires.hpp>

namespace boost { namespace network { namespace http {

    template <class Tag>
    struct basic_response;

    template <class Tag>
    struct basic_request;

    namespace impl {

        template <class Tag, class T>
        void destination(basic_response<Tag> & response, T const & value, mpl::false_ const &) {
            response << ::boost::network::destination(value);
        }

        template <class Tag, class T>
        void destination(basic_response<Tag> & response, T const & future, mpl::true_ const &) {
            response.destination(future);
        }

    }

    template <class Tag, class T>
    inline void
    destination(basic_response<Tag> & response, T const & value) {
        impl::destination(response, value, is_async<Tag>());
    }

    template <class R>
    struct ServerRequest;

    template <class Tag, class T>
    inline void
    destination_impl(basic_request<Tag> & request, T const & value, tags::server) {
        request.destination = value;
    }

    template <class Tag, class T>
    inline void
    destination_impl(basic_request<Tag> & request, T const & value, tags::pod) {
        request.destination = value;
    }

    template <class Tag, class T>
    inline void
    destination_impl(basic_request<Tag> & request, T const & value, tags::normal) {
        request.destination(value);
    }

    template <class Tag, class T>
    inline void
    destination_impl(basic_request<Tag> & request, T const & value, tags::client) {
        destination_impl(request, value, typename pod_or_normal<Tag>::type());
    }

    template <class Tag, class T>
    inline void
    destination(basic_request<Tag> & request, T const & value) {
        destination_impl(request, value, typename client_or_server<Tag>::type());
    }

} // namespace http

    namespace impl {
        
        template <class Message, class ValueType, class Async>
        inline void destination(Message const & message, ValueType const & destination_, http::tags::http_server, Async) {
            message.destination = destination_;
        }

    } /* impl */

} // namespace network

} // namespace boost

#include <boost/network/message/modifiers/destination.hpp>

#endif // BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_MODIFIER_DESTINATION_HPP_20100624

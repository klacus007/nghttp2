/*
 * nghttp2 - HTTP/2 C Library
 *
 * Copyright (c) 2014 Tatsuhiro Tsujikawa
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include "nghttp2_config.h"

#include <nghttp2/asio_http2_server.h>

#include "asio_server_http2_impl.h"
#include "asio_server.h"
#include "template.h"

namespace nghttp2 {

namespace asio_http2 {

namespace server {

http2::http2() : impl_(make_unique<http2_impl>()) {}

http2::~http2() {}

void http2::listen_and_serve(const std::string &address, uint16_t port) {
  impl_->listen_and_serve(address, port);
}

void http2::num_threads(size_t num_threads) { impl_->num_threads(num_threads); }

void http2::tls(std::string private_key_file, std::string certificate_file) {
  impl_->tls(std::move(private_key_file), std::move(certificate_file));
}

void http2::backlog(int backlog) { impl_->backlog(backlog); }

bool http2::handle(std::string pattern, request_cb cb) {
  return impl_->handle(std::move(pattern), std::move(cb));
}

} // namespace server

} // namespace asio_http2

} // namespace nghttp2

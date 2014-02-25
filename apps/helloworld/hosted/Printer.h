//          Copyright Boston University SESA Group 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#ifndef APPS_HELLOWORLD_HOSTED_PRINTER_H_
#define APPS_HELLOWORLD_HOSTED_PRINTER_H_

#include <string>

#include <ebbrt/Message.h>
#include <ebbrt/StaticSharedEbb.h>

#include "../StaticEbbIds.h"

class Printer : public ebbrt::StaticSharedEbb<Printer>,
                public ebbrt::Messagable<Printer> {
 public:
  Printer();

  static ebbrt::Future<void> Init();
  void Print(std::string string);
  void ReceiveMessage(ebbrt::Messenger::NetworkId nid, ebbrt::Buffer buffer);
};

constexpr auto printer = ebbrt::EbbRef<Printer>(kPrinterEbbId);

#endif  // APPS_HELLOWORLD_HOSTED_PRINTER_H_

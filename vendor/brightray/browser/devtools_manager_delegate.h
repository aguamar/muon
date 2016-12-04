// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE-CHROMIUM file.

#ifndef BROWSER_DEVTOOLS_MANAGER_DELEGATE_H_
#define BROWSER_DEVTOOLS_MANAGER_DELEGATE_H_

#include "base/macros.h"
#include "base/compiler_specific.h"
#include "content/browser/devtools/devtools_http_handler.h"
#include "content/public/browser/devtools_manager_delegate.h"

namespace brightray {

class DevToolsNetworkProtocolHandler;

class DevToolsManagerDelegate : public content::DevToolsManagerDelegate {
 public:

  DevToolsManagerDelegate();
  virtual ~DevToolsManagerDelegate();

  // DevToolsManagerDelegate implementation.
  void Inspect(content::DevToolsAgentHost* agent_host) override {}
  void DevToolsAgentStateChanged(content::DevToolsAgentHost* agent_host,
                                 bool attached) override;
  base::DictionaryValue* HandleCommand(content::DevToolsAgentHost* agent_host,
                                       base::DictionaryValue* command) override;
  std::string GetTargetType(content::RenderFrameHost* host) override
    {return std::string();}
  std::string GetTargetTitle(content::RenderFrameHost* host) override
    {return std::string();}
  scoped_refptr<content::DevToolsAgentHost> CreateNewTarget(
    const GURL& url) override {return nullptr;}
  std::string GetDiscoveryPageHTML() override
    {return std::string();}
  std::string GetFrontendResource(const std::string& path) override
    {return std::string();}

 private:
  std::unique_ptr<DevToolsNetworkProtocolHandler> handler_;

  DISALLOW_COPY_AND_ASSIGN(DevToolsManagerDelegate);
};

}  // namespace brightray

#endif  // BROWSER_DEVTOOLS_MANAGER_DELEGATE_H_

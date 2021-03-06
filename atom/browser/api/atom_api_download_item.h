// Copyright (c) 2015 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ATOM_BROWSER_API_ATOM_API_DOWNLOAD_ITEM_H_
#define ATOM_BROWSER_API_ATOM_API_DOWNLOAD_ITEM_H_

#include <string>

#include "atom/browser/api/trackable_object.h"
#include "base/files/file_path.h"
#include "components/download/public/common/download_item.h"
#include "native_mate/handle.h"
#include "url/gurl.h"

namespace atom {

namespace api {

using download::DownloadDangerType;

class DownloadItem : public mate::TrackableObject<DownloadItem>,
                     public download::DownloadItem::Observer {
 public:
  static mate::Handle<DownloadItem> Create(v8::Isolate* isolate,
                                           download::DownloadItem* item);

  static void BuildPrototype(v8::Isolate* isolate,
                             v8::Local<v8::FunctionTemplate> prototype);

  void Pause();
  bool IsPaused() const;
  void Resume();
  bool CanResume() const;
  void Cancel();
  int64_t GetReceivedBytes() const;
  int64_t GetTotalBytes() const;
  std::string GetMimeType() const;
  bool HasUserGesture() const;
  std::string GetFilename() const;
  base::FilePath GetTargetFilePath() const;
  std::string GetContentDisposition() const;
  const GURL& GetURL() const;
  download::DownloadItem::DownloadState GetState() const;
  bool IsDone() const;
  void SetSavePath(const base::FilePath& path);
  base::FilePath GetSavePath() const;
  std::string GetGuid() const;
  void SetPrompt(bool prompt);
  bool ShouldPrompt();
  bool IsDangerous() const;
  DownloadDangerType GetDangerType() const;

 protected:
  DownloadItem(v8::Isolate* isolate, download::DownloadItem* download_item);
  ~DownloadItem();

  // Override download::DownloadItem::Observer methods
  void OnDownloadUpdated(download::DownloadItem* download) override;
  void OnDownloadRemoved(download::DownloadItem* download) override;
  void OnDownloadDestroyed(download::DownloadItem* download) override;

 private:
  base::FilePath save_path_;
  download::DownloadItem* download_item_;
  bool prompt_;

  DISALLOW_COPY_AND_ASSIGN(DownloadItem);
};

}  // namespace api

}  // namespace atom

#endif  // ATOM_BROWSER_API_ATOM_API_DOWNLOAD_ITEM_H_

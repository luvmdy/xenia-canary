/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2020 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_APP_EMULATOR_WINDOW_H_
#define XENIA_APP_EMULATOR_WINDOW_H_

#include <memory>
#include <string>

#include "xenia/ui/loop.h"
#include "xenia/ui/menu_item.h"
#include "xenia/ui/window.h"
#include "xenia/xbox.h"

namespace xe {
class Emulator;
}  // namespace xe

namespace xe {
namespace app {

class EmulatorWindow {
 public:
  virtual ~EmulatorWindow();

  static std::unique_ptr<EmulatorWindow> Create(Emulator* emulator);

  Emulator* emulator() const { return emulator_; }
  ui::Loop* loop() const { return loop_.get(); }
  ui::Window* window() const { return window_.get(); }

  void UpdateTitle();
  void ToggleFullscreen();
  void SetInitializingShaderStorage(bool initializing);

 private:
  explicit EmulatorWindow(Emulator* emulator);

  bool Initialize();

  void FileDrop(const std::filesystem::path& filename);
  void FileOpen();
  void RecentListUpdater(const std::filesystem::path& path);
  void RecentList(int index);
  void FileClose();
  void ShowContentDirectory();
  void CheckHideCursor();
  void CpuTimeScalarReset();
  void CpuTimeScalarSetHalf();
  void CpuTimeScalarSetDouble();
  void CpuBreakIntoDebugger();
  void CpuBreakIntoHostDebugger();
  void GpuTraceFrame();
  void GpuClearCaches();
  void ShowHelpWebsite();
  void ShowCommitID();

  Emulator* emulator_;
  std::unique_ptr<ui::Loop> loop_;
  std::unique_ptr<ui::Window> window_;
  std::string base_title_;
  std::filesystem::path global_recent_paths_[10];
  uint64_t cursor_hide_time_ = 0;
  bool initializing_shader_storage_ = false;
};

}  // namespace app
}  // namespace xe

#endif  // XENIA_APP_EMULATOR_WINDOW_H_

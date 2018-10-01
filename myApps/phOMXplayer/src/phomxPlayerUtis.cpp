#include "phomxPlayerUtis.h"

void phOmxPlayerUtils::sig_handler(int s)
{
  if (s==SIGINT && !g_abort)
  {
     signal(SIGINT, SIG_DFL);
     g_abort = true;
     return;
  }
  signal(SIGABRT, SIG_DFL);
  signal(SIGSEGV, SIG_DFL);
  signal(SIGFPE, SIG_DFL);
  if (NULL != m_keyboard)
  {
     m_keyboard->Close();
  }
  abort();
}

void phOmxPlayerUtils::print_usage() {
  printf(
#include "help.h"
  );
}

void phOmxPlayerUtils::print_keybindings() {
  printf(
#include "keys.h"
  );
}

void phOmxPlayerUtils::print_version() {
  printf("omxplayer - Commandline multimedia player for the Raspberry Pi\n");
  printf("        Build date: %s\n", VERSION_DATE);
  printf("        Version   : %s [%s]\n", VERSION_HASH, VERSION_BRANCH);
  printf("        Repository: %s\n", VERSION_REPO);
}

/*************
* FileUtils
**************/

bool phOmxPlayerUtils::Exists(const std::string& path) {
  struct stat buf;
  auto error = stat(path.c_str(), &buf);
  return !error || errno != ENOENT;
}


bool phOmxPlayerUtils::IsURL(const std::string& str) {
  auto result = str.find("://");
  if(result == std::string::npos || result == 0)
    return false;

  for(size_t i = 0; i < result; ++i)
  {
    if(!isalpha(str[i]))
      return false;
  }
  return true;
}

bool phOmxPlayerUtils::IsPipe(const std::string& str) {
  if (str.compare(0, 5, "pipe:") == 0)
    return true;
  return false;
}

/*
static void PrintSubtitleInfo()
{
  auto count = m_omx_reader.SubtitleStreamCount();
  size_t index = 0;

  if(m_has_external_subtitles)
  {
    ++count;
    if(!m_player_subtitles.GetUseExternalSubtitles())
      index = m_player_subtitles.GetActiveStream() + 1;
  }
  else if(m_has_subtitle)
  {
      index = m_player_subtitles.GetActiveStream();
  }

  printf("Subtitle count: %d, state: %s, index: %d, delay: %d\n",
         count,
         m_has_subtitle && m_player_subtitles.GetVisible() ? " on" : "off",
         index+1,
         m_has_subtitle ? m_player_subtitles.GetDelay() : 0);
}
*/

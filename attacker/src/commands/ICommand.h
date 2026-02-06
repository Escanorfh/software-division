#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <memory>

class ICommand {
public:
  virtual ~ICommand() = default;
  virtual void execute() = 0;
};

using ICommandPtr = std::shared_ptr<ICommand>;

#endif // ICOMMAND_H
